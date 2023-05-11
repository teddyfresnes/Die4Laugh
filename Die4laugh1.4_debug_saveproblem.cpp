#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <windows.h>
#include <algorithm>
#include <fstream>
#include <bits/stdc++.h>
#include <math.h>

#define SIZE_OF_GROUND 1000
#define NB_KILOMETERS 500

/*
	Name: KOEHREN Teddy
	Date: 08/02/2022
	Description: awesome game
*/

// Dear programmer
// When I wrote Die4laugh, only god and I knows how it worked.
// Now, only god knows it!
//
// Therefore, if you are trying to optimize/edit this game and it fails (most surely),
// please increase this counter as a warning for the next person:
//
// total_hours_wasted_here = 45
//


void clean()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


void wait_user()
{
	printf("\nAppuyez sur n'importe quel touche pour continuer...\n");
	_getch();
}


void encrypt()
{
	Sleep(100);
	int key = 3;
	char c;
	std::remove("save_old.csv");
	std::rename("save.csv", "save_old.csv");
	// printf("100"); wait_user();
    std::fstream fin; //File to read from
    std::fstream fout; //Temporary file
 
    fin.open("save_old.csv", std::fstream::in);
    fout.open("save.csv", std::fstream::out);
	
	fin >> std::noskipws >> c;
	// printf("grab premier charactere : (%c)\n",char(c));
 
	if (char(c) == 'q') // si deja crypté
	{
		// printf("101"); wait_user();
		fin.close();
		fout.close();
		std::remove("save.csv");
		std::rename("save_old.csv", "save.csv");
		// printf("102"); wait_user();
	}
    else
	{
		int temp = (c + key);
		fout << (char)temp;
		// Reading originalfile till
		// end of file
		while (fin >> std::noskipws >> c)
		{
	 
			// Remove the key from the
			// character
			//printf("old %c",c);
			int temp = (c + key);
			//printf("attention ça crash decrypt temp %c\n",temp);
			fout << (char)temp;
		}
		
		fin.close();
		fout.close();
	}
	
	// printf("103"); wait_user();
	std::remove("save_old.csv");
	// printf("104"); wait_user();
	Sleep(100);
}
 

void decrypt()
{
	Sleep(100);
	int key = 3;
	char c;
	std::remove("save_old.csv");
	std::rename("save.csv", "save_old.csv");
	// printf("100"); wait_user();
    std::fstream fin; //File to read from
    std::fstream fout; //Temporary file
 
    fin.open("save_old.csv", std::fstream::in);
    fout.open("save.csv", std::fstream::out);
	
	fin >> std::noskipws >> c;
	// printf("grab premier charactere : (%c)\n",char(c));
 
	if (char(c) == 'n') // si deja décrypté
	{
		// printf("101"); wait_user();
		fin.close();
		fout.close();
		std::remove("save.csv");
		std::rename("save_old.csv", "save.csv");
		// printf("102"); wait_user();
	}
    else
	{
		int temp = (c - key);
		fout << (char)temp;
		// Reading originalfile till
		// end of file
		while (fin >> std::noskipws >> c)
		{
	 
			// Remove the key from the
			// character
			// printf("old %c",c);
			int temp = (c - key);
			// printf("attention ça crash decrypt temp %c\n",temp);
			fout << (char)temp;
		}
		
		fin.close();
		fout.close();
	}
	
	// printf("103"); wait_user();
	std::remove("save_old.csv");
	// printf("104"); wait_user();
	Sleep(100);
}


bool comp(std::string a, std::string b) // pour tri alphabétique
{
	if (a.compare("") == 0) a = "ZZZ";
	if (b.compare("") == 0) b = "ZZZ";
	//printf("a %c < b %c\n",a[0],b[0]);
	return a[0] < b[0];
}


namespace patch // pour utiliser to_string
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}


class Die4laugh
{
	private:
		// attributs
		int days;
		int kilometers;
		int energy;
		int energy_max;
		int energy_to_brb;
		std::string location;
		int nb_locations; // pour le dev
		int monsters;
		int monsters_control;
		int bag[10];
		int bag_size;
		int nb_items; // pour le dev
		int ground[SIZE_OF_GROUND];
		int ground_home[SIZE_OF_GROUND];
		int ground_first[SIZE_OF_GROUND];
		int ground_index[SIZE_OF_GROUND];
		int ground_size;
		bool deep_mode;
		bool drained;
		bool drained_location;
		bool home;
		bool camping;
		float survival_chance_ouside;
		int day_outside;
		bool stuck;
		int kilometers_exhausted[NB_KILOMETERS];
		int kilometers_building[NB_KILOMETERS];
		//int kilometers_save[NB_KILOMETERS][SIZE_OF_GROUND];
		int* kilometers_save[NB_KILOMETERS];
		int camp_def;
		int camp_defadd;
		int display_camp_def;
		bool slot1;
		bool slot2;
		int decoration;
		int z_attack;
		
		//attributs states
		bool no_drugs;
		bool dependant;
		bool water_day;
		bool food_day;
		bool drug_day;
		bool thirst;
		bool big_thirst;
		bool injury;
		bool ill;
		bool convalescent;
		bool meds;
		bool terror;
		bool alcohol;
		bool hangover;
		
		//attributes builds
		bool ch_waterwell;
		int ch_waterwell_nj;
		bool waterwell_today;
		
		bool ch_workshop;
		int ch_workshop_nj;
		int workshop_energy;
		
		bool ch_foundation;
		int ch_foundation_nj;
		
		bool ch_shed;
		int ch_shed_nj;
		
		bool ch_factory;
		int ch_factory_nj;
		
		bool ch_watchtower;
		int ch_watchtower_nj;
		
		int ch_cuisine;
		int ch_cuisine_nj;
		
		int ch_home;
		int ch_home_nj;
		
		int ch_barricade;
		int ch_barricade_nj;
		
		bool ch_fireworks;
		int ch_fireworks_nj;
		
		bool ch_vegetable;
		int ch_vegetable_nj;
		
		//gestion des fichiers
		std::string username_input;
		int index_save;
		
		//stats
		int stat_max_days;
		int stat_max_killometers;
		int stat_number_killometers;
		int stat_number_drugs;
		int stat_number_alcohol;
		int stat_number_kills;
		int stat_number_hardkills;
		int stat_number_brokenitems;
		int stat_number_crafteditems;
		int stat_number_decoration;
		int stat_number_death_outside;
		int stat_number_death_inside;
		int stat_number_death_drugs;
		int stat_number_death_water;
		int stat_number_death_ill;
		int stat_number_death_suicide;
		int stat_number_death_bomb;
		int stat_success_chainsaw;
		int stat_success_cardoor;
		int stat_success_vh;
		int stat_max_def;
		int stat_success_spice;
		int stat_success_the_king;
		int stat_success_maso;
		int stat_success_castle;
		int total_days;
		
				
	public:
		// constructeur
		Die4laugh();
		
		// méthodes
		void sort_empty_racism(int * my_array, int size);
		void sort_bag_alphabet();
		void sort_ground_index();
		
		void fstat_get(std::string username);
		void fstat_write();
		void fstat_profile(std::string username);
		void fstat_scoreboard();
		
		void display_day0();
		std::string print_item(int id, int type);
		void reset_ground();
		void display_states();
		void display_bag();
		void display_ground();
		void make_my_ground_firstindex();
		
		void reload_location();
		
		int open(int * items, int size);
		int check_bag(int id, int avoid_id);
		int count_camp_item(int id);
		
		void remove_camp_item(int id, int remove_nb);
		void add_camp_item(int id, int add_nb);
		void use_item(int number);
		void move_item(int number);
		void add_item(int number);
		
		void a_use_items();
		void a_dig_items();
		void a_dig_location_items();
		void a_next_kilometer();
		void a_back_to_home();
		void a_sleep_home();
		void a_sleep_outside();
		void a_builds_camp();
		void a_ch_waterwell();
		void a_runaway();
		void a_try_to_kill();
		void a_ch_workshop();
		
		void stuck_f();
		void new_day();
		void death(int why);
		
		void display_actions();
		void wait_for_action();
		void refresh_at_display();
		void display_base();
};


Die4laugh::Die4laugh()
{
	int i;
	days = 1;
	kilometers = 0;
	energy = 6;
	energy_max = 6;
	energy_to_brb = 0;
	location = "Campement";
	monsters = 0;
	monsters_control = 3;
	bag_size = 5;
	ground_size = sizeof(ground)/sizeof(ground[0]);
	bag[0] = 3;
	bag[1] = 1;
	bag[2] = 0;
	bag[3] = 0;
	bag[4] = 0;
	bag[5] = 0;
	bag[6] = 0;
	bag[7] = 0;
	bag[8] = 0;
	bag[9] = 0;
	for (i=0; i<ground_size; i++) // sol vide
	{
		ground[i] = 0;
		ground_home[i] = 0;
	}
	ground[0] = 2;
	// ground[1] = 35;
	// ground[2] = 35;
	// ground[3] = 35;
	// ground[4] = 35;
	// ground[5] = 36;
	// ground[6] = 36;
	// ground[7] = 36;
	// ground[8] = 73;
	// ground[9] = 120;
	// ground[10] = 114;
	// ground[11] = 33;
	// ground[12] = 33;
	// ground[13] = 33;
	// ground[14] = 34;
	// ground[15] = 34;
	// ground[16] = 34;
	// ground[17] = 73;
	// ground[18] = 89;
	// ground[17] = 140;
	// ground[18] = 141;
	// ground[19] = 132;
	// ground[20] = 6;
	// ground[21] = 6;
	// ground[22] = 6;
	// ground[23] = 5;
	// ground[24] = 4;
	// ground[25] = 4;
	deep_mode = false;
	drained = false;
	drained_location = false;
	home = true;
	camping = false;
	survival_chance_ouside = 0.0f;
	day_outside = 0;
	stuck = false;
	for (int i = 0; i < NB_KILOMETERS; ++i)
	{
		kilometers_save[i] = new int[SIZE_OF_GROUND];
	}
	
	ch_workshop = false;
	workshop_energy = 3;
	ch_workshop_nj = 6;
	
	ch_waterwell = false;
	waterwell_today = false;
	ch_waterwell_nj = 8;
	
	ch_foundation = false;
	ch_foundation_nj = 8;

	ch_shed = false;
	ch_shed_nj = 6;
	
	ch_factory = false;
	ch_factory_nj = 8;
	
	ch_watchtower = false;
	ch_watchtower_nj = 10;
	
	ch_cuisine = 0;
	ch_cuisine_nj = 6;
	
	ch_home = 0;
	ch_home_nj = 2;
	
	ch_barricade = 0;
	ch_barricade_nj = 3;
	
	ch_fireworks = 0;
	ch_fireworks_nj = 6;
	
	ch_vegetable = 0;
	ch_vegetable_nj = 6;
	
	for (i=0; i<sizeof(kilometers_exhausted)/(sizeof(kilometers_exhausted[0])); i++)
	{
		kilometers_exhausted[i] = rand()%8+1;
	}
	for (i=0; i<sizeof(kilometers_save)/(sizeof(kilometers_save[0])); i++)
	{
		kilometers_save[i][0] = -1;
	}
	for (i=0; i<sizeof(kilometers_building)/(sizeof(kilometers_building[0])); i++)
	{
		kilometers_building[i] = -1;
	}
	
	camp_def = 10;
	camp_defadd = 0;
	slot1 = false;
	slot2 = false;
	decoration = 0;
	z_attack =  rand()%20-10;
	
	//fichiers
	username_input = "";
	index_save = -1;
	
	//states
	no_drugs = true;
	dependant = false;
	water_day = false;
	food_day = false;
	drug_day = false;
	thirst = false;
	big_thirst = false;
	injury = false;
	ill = false;
	convalescent = false;
	meds = false;
	terror = false;
	alcohol = false;
	hangover = false;
	
	srand(time(NULL));
	
	display_day0();
}


void Die4laugh::sort_empty_racism(int * my_array, int size)
{
	int i, position_empty, last_position;
	bool last = true;
	
	position_empty = -1;
	last_position = -1;
	for (i=0; i<size; i++)
	{
		if (my_array[i] != 0)
		{
			last_position = i; // on recupere la derniere position pour la mettre dans la premiere place libre
		}
	}

	for (i=0; i<size; i++)
	{
		if (my_array[i] == 0)
		{
			position_empty = i;
			break;
		}
	} 
	
	if (position_empty <= last_position && position_empty != (-1) && last_position != (-1)) // pour ne pas depasser après la dernière position trouvé + si pas de position trouvé
	{
		my_array[position_empty] = my_array[last_position];
		my_array[last_position] = 0;
	}
}


void Die4laugh::sort_bag_alphabet()
{
	int i, id;
	std::string array_string[bag_size];
	
	for (i=0; i<bag_size; i++)
	{
		array_string[i] = (print_item(bag[i],0));
	}
	
	//for (i=0; i<bag_size; i++) printf("avant tri: %s\n",array_string[i].c_str());
	std::sort(array_string, array_string + bag_size, comp);
	//for (i=0; i<bag_size; i++) printf("après tri: %s\n",array_string[i].c_str());
	
	for (i=0; i<bag_size; i++) // pour tt les éléments du tableau
	{
		for (id=0; id<nb_items; id++) // pour tt les objets qui existent
		{
			//printf("\nd_item=%d str_item=%s /// d_id=%d str_id=%s",i,array_string[i].c_str(),id,print_item(id,0).c_str());
			if (array_string[i].compare(print_item(id,0)) == 0) // si l'objet du tableau est égale à l'item alors on récupère son id
			{
				//printf("\nOK !");
				bag[i] = id;
				break;
			}
		}
	}
}


void Die4laugh::sort_ground_index()
{
	int i, j, k, temp, temp2;
	
	/*for(i=0;i<n;i++) // exemple algo de tri
	{		
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}*/
	
	// for (i=0; ground_first[i] != 0; i++) printf("B4 : first_[i] = %d\n",ground_first[i]);
	/* TRI PAR NOMBRE */
	i = 0;
	while (ground_first[i] != 0)
	{
		j = i+1;
		while (ground_first[j] != 0)
		{
			// if(ground_first[i]>ground_first[j])
			if(print_item(ground_first[i],0) > print_item(ground_first[j],0))
			{
				temp = ground_first[i];
				temp2 = ground_index[i];
				ground_first[i] = ground_first[j];
				ground_index[i] = ground_index[j];
				ground_first[j] = temp;
				ground_index[j] = temp2;
			}
			j++;
		}
		i++;
	}
	
	// for (i=0; ground_first[i] != 0; i++) printf("AF : first_[i] = %d\n",ground_first[i]);
	
	/* TRI PAR INDEX */
	int last_position;
	reset_ground();
	
	i = 0;
	do // pour chaque element i de ground_first
	{
		// printf("ID : ground_first[i] %d\n",ground_first[i]);
		for (j=0; j<ground_index[i]; j++) // pour chaque element j de ground_index 
		{
			k=0;
			while (ground[k] != 0)
					k++;
				
			ground[k] = ground_first[i];
			// printf("Ajout de ground_index[i] %d à ground[k] %d\n",ground_first[i],ground[k]);
		}
		
		i++;
	} while(ground_first[i] != 0);
	
	
	/* TRI ALPHABETIQUE PAR INDEX */
	
	/*int ground_temp[SIZE_OF_GROUND];
	
	
	int i, id;
	std::string array_string[bag_size];
	
	for (i=0; i<bag_size; i++)
	{
		array_string[i] = (print_item(bag[i],0));
	}
	
	//for (i=0; i<bag_size; i++) printf("avant tri: %s\n",array_string[i].c_str());
	std::sort(array_string, array_string + bag_size, comp);
	//for (i=0; i<bag_size; i++) printf("après tri: %s\n",array_string[i].c_str());
	
	for (i=0; i<bag_size; i++) // pour tt les éléments du tableau
	{
		for (id=0; id<nb_items; id++) // pour tt les objets qui existent
		{
			//printf("\nd_item=%d str_item=%s /// d_id=%d str_id=%s",i,array_string[i].c_str(),id,print_item(id,0).c_str());
			if (array_string[i].compare(print_item(id,0)) == 0) // si l'objet du tableau est égale à l'item alors on récupère son id
			{
				//printf("\nOK !");
				bag[i] = id;
				break;
			}
		}
	}*/
}


void Die4laugh::fstat_get(std::string username)
{	
	/* vérifier si le profil existe, sinon il le crée */
	
	std::fstream the_file;
	int i;
	int number_columns;
	int name_index = -1;
	bool name_not_find = true;
	std::string file_name = "save.csv";
	
	// printf("103,5"); wait_user();
	std::ifstream f(file_name.c_str());
	if (f.good() == false) // crée le fichier si il n'existe pas
	{
		std::ofstream MyFile("save.csv");
		//MyFile << "name,max_days,max_kilometers,kilometers,drugs,alcohol,kills,hardkills,brokenitems,crafteditems,decoration,death_outside,death_inside,death_drugs,death_water,death_ill,death_suicide,death_bomb,chainsaw,cardoor,vh,maxdef,spice,king,maso,castle,NBDAYS\n";
		MyFile << "n,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26\n";
		MyFile.close();
	}
	f.close();
	// printf("104.5"); wait_user();
	decrypt(); // pas d'open sinon fonctionne pas
	// printf("104,75"); wait_user();
	the_file.open("save.csv",std::ios::in);
	printf("105"); wait_user();
	/* check if le pseudo exist */
	if (the_file.is_open())
	{ //checking whether the file is open
		printf("105.1"); wait_user();
		std::string first_line;
		printf("105.2"); wait_user();
		getline(the_file, first_line);
		printf("105.3"); wait_user();
		number_columns = std::count(first_line.begin(), first_line.end(), ',');
		printf("105.4"); wait_user();
	}
	the_file.close(); //close the file object.
	
	printf("106"); wait_user();
	the_file.open("save.csv",std::ios::in);
	if (the_file.is_open())
	{ //checking whether the file is open
		std::string line;
		std::string delimiter = ",";
		i = 0;
		while(getline(the_file, line))
		{ //read data from file object and put it into string.
			fflush(stdout);
			std::cout << line << std::endl;
			printf("\n\ni = %d\n",i);
			std::string name = line.substr(0, line.find(delimiter)); // pseudo
			std::cout << "\npseudo trouvé718=" << name << "\n"; //print the data of the string
			name_not_find = name.compare(username);
			if (name_not_find == 0) // si le nom est trouvé
			{
				printf("trouvé à %d",i);
				name_index = i;
				index_save = i;
				break;
			}
			i++;
		}
		the_file.close(); //close the file object.
	}
	// printf("last : %d, index = %d, not_find = %d",i,name_index,name_not_find);
	printf("107"); wait_user();
	/* ajoute le pseudo si il n'existe pas */
	if (name_not_find) 
	{
		index_save = i;
		
		std::ofstream fout;
		std::ifstream fin;
		fin.open("save.csv");
		fout.open ("save.csv",std::ios::app);
		if(fin.is_open())
		{
			std::string new_profile;
			new_profile = username + ",";
			for (i=0; i<number_columns-1; i++) new_profile += "0,";
			new_profile += "0\n";
			fout << new_profile ;
		}
		fin.close();
		fout.close();
	}
	
	printf("108"); wait_user();
	
	the_file.open("save.csv",std::ios::in);
	
	printf("109"); wait_user();
	/* récupération données */
	if (the_file.is_open())
	{ 
		std::string line;
		std::string delimiter = ",";
		i = -1;
		while (i != index_save && getline(the_file, line))
		{
			printf("ligne %d et index save %d : %s\n",i,index_save,line.c_str());
			i++;
		}
		printf("109.1"); wait_user();
		std::stringstream line_to_split(line);
		std::string segment;
		std::vector<std::string> seglist;
		printf("ligne: %s \n",line.c_str());
		while(std::getline(line_to_split, segment, ',')) // cree un std::vector<std::string> seglist{ élements };
		{
		   seglist.push_back(segment);
		   printf("segment: %s \n",segment.c_str());
		}
		printf("109.3"); wait_user();
		printf("1: seglist[1].c_str() = %s",seglist[1].c_str()); wait_user();
		stat_max_days = atoi(seglist[1].c_str());
		printf("ligne : %s str first : %s d\n",line.c_str(),seglist[1].c_str(),atoi(seglist[1].c_str()));
		stat_max_killometers = atoi(seglist[2].c_str());
		printf("ligne : %s str 2 : %s d\n",line.c_str(),seglist[2].c_str(),atoi(seglist[2].c_str()));
		stat_number_killometers = atoi(seglist[3].c_str());
		stat_number_drugs = atoi(seglist[4].c_str());
		stat_number_alcohol = atoi(seglist[5].c_str());
		stat_number_kills = atoi(seglist[6].c_str());
		stat_number_hardkills = atoi(seglist[7].c_str());
		stat_number_brokenitems = atoi(seglist[8].c_str());
		stat_number_crafteditems = atoi(seglist[9].c_str());
		stat_number_decoration = atoi(seglist[10].c_str());
		stat_number_death_outside = atoi(seglist[11].c_str());
		stat_number_death_inside = atoi(seglist[12].c_str());
		stat_number_death_drugs = atoi(seglist[13].c_str());
		stat_number_death_water = atoi(seglist[14].c_str());
		stat_number_death_ill = atoi(seglist[15].c_str());
		stat_number_death_suicide = atoi(seglist[16].c_str());
		printf("109.6"); wait_user();
		stat_number_death_bomb = atoi(seglist[17].c_str());
		stat_success_chainsaw = atoi(seglist[18].c_str());
		stat_success_cardoor = atoi(seglist[19].c_str());
		stat_success_vh = atoi(seglist[20].c_str());
		stat_max_def = atoi(seglist[21].c_str());
		stat_success_spice = atoi(seglist[22].c_str());
		stat_success_the_king = atoi(seglist[23].c_str());
		stat_success_maso = atoi(seglist[24].c_str());
		stat_success_castle = atoi(seglist[25].c_str());
		total_days = atoi(seglist[26].c_str());
		printf("109.5"); wait_user();
		std::string name = line.substr(0, line.find(delimiter)); // pseudo
		name_not_find = name.compare(username_input);
		
		the_file.close(); //close the file object.
		printf("109.7"); wait_user();
	}
	printf("110"); wait_user();
	
	encrypt();
}


void Die4laugh::fstat_write()
{
	// printf("lolilol"); wait_user();
	decrypt();
	printf("stat kilometers : stat_number_killometers %d",stat_number_killometers);
	std::string line_to_write = username_input
		+ "," + patch::to_string(stat_max_days) + "," + patch::to_string(stat_max_killometers) + "," + patch::to_string(stat_number_killometers) + "," + patch::to_string(stat_number_drugs) + "," + patch::to_string(stat_number_alcohol) + "," + patch::to_string(stat_number_kills)
		+ "," + patch::to_string(stat_number_hardkills) + "," + patch::to_string(stat_number_brokenitems) + "," + patch::to_string(stat_number_crafteditems) + "," + patch::to_string(stat_number_decoration) + "," + patch::to_string(stat_number_death_outside) + "," + patch::to_string(stat_number_death_inside) + "," + patch::to_string(stat_number_death_drugs)
		+ "," + patch::to_string(stat_number_death_water) + "," + patch::to_string(stat_number_death_ill) + "," + patch::to_string(stat_number_death_suicide) + "," + patch::to_string(stat_number_death_bomb) + "," + patch::to_string(stat_success_chainsaw) + "," + patch::to_string(stat_success_cardoor)
		+ "," + patch::to_string(stat_success_vh) + "," + patch::to_string(stat_max_def) + "," + patch::to_string(stat_success_spice) + "," + patch::to_string(stat_success_the_king) + "," + patch::to_string(stat_success_maso) + "," + patch::to_string(stat_success_castle)
		+ "," + patch::to_string(total_days);

	// printf("lol"); wait_user();
	std::remove("save_old.csv");
	std::rename("save.csv", "save_old.csv");
	// printf("rename\n"); wait_user();
    std::ifstream filein("save_old.csv"); //File to read from
    std::ofstream fileout("save.csv"); //Temporary file
	// printf("lol2"); wait_user();
    if(!filein || !fileout)
    {
        std::cout << "\n\nproblem with save" << std::endl;
    }

    std::string strTemp;
    while(filein >> strTemp)
    {
		printf("\nline : %s",strTemp.c_str()); wait_user();
		if (strTemp.find(username_input+",") != std::string::npos) // npos pour chercher le pseudo en entier
		{
			printf("\nTROUVER TRERE : %s\n",strTemp.c_str()); wait_user();
            strTemp = line_to_write;
			printf("ligne remplacé %s\n",line_to_write.c_str()); wait_user();
        }
        strTemp += "\n";
        fileout << strTemp;
        //if(found) break;
    }
	std::remove("save_old.csv");
	
	// encrypt();
}


void Die4laugh::fstat_profile(std::string username)
{
	if (username.compare("- -") == 1)
	{
		clean();
		
		fstat_get(username); // recupere les stats dans les variables
		
		printf("Profil de %s\n\n",username.c_str());
		printf("Statistiques :\n");
		if (stat_max_days > 0) printf(" {%d} Nombre de jours survécus au maximum\n",stat_max_days);
		if (stat_max_def > 0) printf(" {%d} Défenses maximum mis en place\n",stat_max_def);
		if (stat_max_killometers > 0) printf(" {%d} Distance maximum parcourue\n",stat_max_killometers);
		if (stat_number_killometers > 0) printf(" {%d} Distance totale parcourue\n",stat_number_killometers);
		if (stat_number_drugs > 0) printf(" {%d} Nombre de drogues utilisées\n",stat_number_drugs);
		if (stat_number_alcohol > 0) printf(" {%d} Nombre d'alcool ingéré\n",stat_number_alcohol);
		if (stat_number_kills > 0) printf(" {%d} Nombre de zombies tués\n",stat_number_kills);
		if (stat_number_hardkills > 0) printf(" {%d} Nombre de zombies tués à mains nus\n",stat_number_hardkills);
		if (stat_number_brokenitems > 0) printf(" {%d} Nombre d'objets cassés\n",stat_number_brokenitems);
		if (stat_number_crafteditems > 0) printf(" {%d} Nombre de fabrications à l'atelier\n",stat_number_crafteditems);
		if (stat_number_decoration > 0) printf(" {%d} Nombre de décorations\n",stat_number_decoration);
		if (stat_number_death_outside > 0) printf(" {%d} Mort(e) dehors\n",stat_number_death_outside);
		if (stat_number_death_inside > 0) printf(" {%d} Mort(e) dans le campement\n",stat_number_death_inside);
		if (stat_number_death_drugs > 0) printf(" {%d} Mort(e) par dépendance\n",stat_number_death_drugs);
		if (stat_number_death_water > 0) printf(" {%d} Mort(e) désydraté(e)\n",stat_number_death_water);
		if (stat_number_death_ill > 0) printf(" {%d} Mort(e) par maladie\n",stat_number_death_ill);
		if (stat_number_death_suicide > 0) printf(" {%d} Mort(e) par suicide\n",stat_number_death_suicide);
		printf("\nSuccès :\n");
		if (stat_number_death_bomb > 0) printf("{%d} Terroriste (Mort(e) explosé)\n",stat_number_death_bomb);
		if (stat_success_chainsaw > 0) printf(" {%d} Massacre à la tronçonneuse\n",stat_success_chainsaw);
		if (stat_success_cardoor > 0) printf(" {%d} Apprenti mécanicien\n",stat_success_cardoor);
		if (stat_success_vh > 0) printf(" {%d} Nourriture exotique\n",stat_success_vh);
		if (stat_success_spice > 0) printf(" {%d} Better when spicy\n",stat_success_spice);
		if (stat_success_the_king > 0) printf(" {%d} The King Of Rock\n",stat_success_the_king);
		if (stat_success_maso > 0) printf(" {%d} Masochiste\n",stat_success_maso);
		if (stat_success_castle > 0) printf(" {%d} Château construit\n",stat_success_castle);
		;
		stat_success_castle;
		
		printf("\n");
		
		wait_user();
	}
}


void Die4laugh::fstat_scoreboard()
{
	clean();

	/* reset des valeurs */
	stat_max_days = 0;
	stat_max_killometers = 0;
	stat_number_killometers = 0;
	stat_number_drugs = 0;
	stat_number_alcohol = 0;
	stat_number_kills = 0;
	stat_number_hardkills = 0;
	stat_number_brokenitems = 0;
	stat_number_crafteditems = 0;
	stat_number_decoration = 0;
	stat_number_death_outside = 0;
	stat_number_death_inside = 0;
	stat_number_death_drugs = 0;
	stat_number_death_water = 0;
	stat_number_death_ill = 0;
	stat_number_death_suicide = 0;
	stat_number_death_bomb = 0;
	stat_success_chainsaw = 0;
	stat_success_cardoor = 0;
	stat_success_vh = 0;
	stat_max_def = 0;
	stat_success_spice = 0;
	stat_success_the_king = 0;
	stat_success_maso = 0;
	stat_success_castle = 0;
	
	/* pour les pseudos */
	std::string str_stat_max_days = "- -";
	std::string str_stat_max_killometers = "- -";
	std::string str_stat_number_killometers = "- -";
	std::string str_stat_number_drugs = "- -";
	std::string str_stat_number_alcohol = "- -";
	std::string str_stat_number_kills = "- -";
	std::string str_stat_number_hardkills = "- -";
	std::string str_stat_number_brokenitems = "- -";
	std::string str_stat_number_crafteditems = "- -";
	std::string str_stat_number_decoration = "- -";
	std::string str_stat_number_death_outside = "- -";
	std::string str_stat_number_death_inside = "- -";
	std::string str_stat_number_death_drugs = "- -";
	std::string str_stat_number_death_water = "- -";
	std::string str_stat_number_death_ill = "- -";
	std::string str_stat_number_death_suicide = "- -";
	std::string str_stat_number_death_bomb = "- -";
	std::string str_stat_success_chainsaw = "- -";
	std::string str_stat_success_cardoor = "- -";
	std::string str_stat_success_vh = "- -";
	std::string str_stat_max_def = "- -";
	std::string str_stat_success_spice = "- -";
	std::string str_stat_success_the_king = "- -";
	std::string str_stat_success_maso = "- -";
	std::string str_stat_success_castle = "- -";

	decrypt();

	std::fstream the_file;
	
	the_file.open("save.csv",std::ios::in);

	/* récupération données */
	if (the_file.is_open())
	{ 
		int i;
		std::string line;
		std::string delimiter = ",";
		i = -1;
		
		getline(the_file, line); // pass la premiere ligne
		
		while (getline(the_file, line))
		{
			std::stringstream line_to_split(line);
			std::string segment;
			std::vector<std::string> seglist;
			while(std::getline(line_to_split, segment, ',')) // cree un std::vector<std::string> seglist{ élements };
			{
				//printf("element = %s\n",segment.c_str());
				//printf("Ajout dans le tableau segment\n");
				seglist.push_back(segment);
				//printf("OK\n");
				//printf("\n\n");
			}
			//printf("Sortie de la boucle");
			
			/* //////C to C++ SYSTEM TO SPLIT//////
			char line_char[1024];
			std::string segment;
			std::vector<std::string> seglist;
			
			strcpy(line_char, line.c_str());
			
			char *token = strtok(line_char, ",");
			//printf("%s\n", token);
			while (token != NULL)
			{
				token = strtok(NULL, ",");
				//printf("%s\n", token);
				//seglist.push_back(token.c_str());
			}
			*/
			
			
			//printf("Début des grabbing\n");
			if (atoi(seglist[1].c_str()) > stat_max_days)
			{
				stat_max_days = atoi(seglist[1].c_str());
				str_stat_max_days = seglist[0].c_str(); // on note le pseudo
			}
			if (atoi(seglist[2].c_str()) > stat_max_killometers)
			{
				stat_max_killometers = atoi(seglist[2].c_str());
				str_stat_max_killometers = seglist[0].c_str();
			}
			if (atoi(seglist[3].c_str()) > stat_number_killometers)
			{
				stat_number_killometers = atoi(seglist[3].c_str());
				str_stat_number_killometers = seglist[0].c_str();
			}
			if (atoi(seglist[4].c_str()) > stat_number_drugs)
			{
				stat_number_drugs = atoi(seglist[4].c_str());
				str_stat_number_drugs = seglist[0].c_str();
			}
			if (atoi(seglist[5].c_str()) > stat_number_alcohol)
			{
				stat_number_alcohol = atoi(seglist[5].c_str());
				str_stat_number_alcohol = seglist[0].c_str();
			}
			if (atoi(seglist[6].c_str()) > stat_number_kills)
			{
				stat_number_kills = atoi(seglist[6].c_str());
				str_stat_number_kills = seglist[0].c_str();
			}
			if (atoi(seglist[7].c_str()) > stat_number_hardkills)
			{
				stat_number_hardkills = atoi(seglist[7].c_str());
				str_stat_number_hardkills = seglist[0].c_str();
			}
			if (atoi(seglist[8].c_str()) > stat_number_brokenitems)
			{
				stat_number_brokenitems = atoi(seglist[8].c_str());
				str_stat_number_brokenitems = seglist[0].c_str();
			}
			if (atoi(seglist[9].c_str()) > stat_number_crafteditems)
			{
				stat_number_crafteditems = atoi(seglist[9].c_str());
				str_stat_number_crafteditems = seglist[0].c_str();
			}
			if (atoi(seglist[10].c_str()) > stat_number_decoration)
			{
				stat_number_decoration = atoi(seglist[10].c_str());
				str_stat_number_decoration = seglist[0].c_str();
			}
			if (atoi(seglist[11].c_str()) > stat_number_death_outside)
			{
				stat_number_death_outside = atoi(seglist[11].c_str());
				str_stat_number_death_outside = seglist[0].c_str();
			}
			if (atoi(seglist[12].c_str()) > stat_number_death_inside)
			{
				stat_number_death_inside = atoi(seglist[12].c_str());
				str_stat_number_death_inside = seglist[0].c_str();
			}
			if (atoi(seglist[13].c_str()) > stat_number_death_drugs)
			{
				stat_number_death_drugs = atoi(seglist[13].c_str());
				str_stat_number_death_drugs = seglist[0].c_str();
			}
			if (atoi(seglist[14].c_str()) > stat_number_death_water)
			{
				stat_number_death_water = atoi(seglist[14].c_str());
				str_stat_number_death_water = seglist[0].c_str();
			}
			if (atoi(seglist[15].c_str()) > stat_number_death_ill)
			{
				stat_number_death_ill = atoi(seglist[15].c_str());
				str_stat_number_death_ill = seglist[0].c_str();
			}
			if (atoi(seglist[16].c_str()) > stat_number_death_suicide)
			{
				stat_number_death_suicide = atoi(seglist[16].c_str());
				str_stat_number_death_suicide = seglist[0].c_str();
			}
			if (atoi(seglist[17].c_str()) > stat_number_death_bomb)
			{
				stat_number_death_bomb = atoi(seglist[17].c_str());
				str_stat_number_death_bomb = seglist[0].c_str();
			}
			if (atoi(seglist[18].c_str()) > stat_success_chainsaw)
			{
				stat_success_chainsaw = atoi(seglist[18].c_str());
				str_stat_success_chainsaw = seglist[0].c_str();
			}
			if (atoi(seglist[19].c_str()) > stat_success_cardoor)
			{
				stat_success_cardoor = atoi(seglist[19].c_str());
				str_stat_success_cardoor = seglist[0].c_str();
			}
			//printf("Ajout 20 : %s\n",seglist[20].c_str());
			if (atoi(seglist[20].c_str()) > stat_success_vh)
			{
				//printf("20: Condition remplie\n");
				stat_success_vh = atoi(seglist[20].c_str());
				//printf("20: Conversion\n");
				str_stat_success_vh = seglist[0].c_str();
				//printf("20: Grabbing\n");
			}
			//printf("Ajout 21 : %s\n",seglist[21].c_str());
			if (atoi(seglist[21].c_str()) > stat_max_def)
			{
				//printf("21: Condition remplie\n");
				stat_max_def = atoi(seglist[21].c_str());
				//printf("21: Conversion\n");
				str_stat_max_def = seglist[0].c_str();
				//printf("21: Grabbing\n");
			}
			//printf("Ajout 22\n");
			if (atoi(seglist[22].c_str()) > stat_success_spice)
			{
				//printf("22: Condition remplie\n");
				stat_success_spice = atoi(seglist[22].c_str());
				//printf("22: Conversion\n");
				str_stat_success_spice = seglist[0].c_str();
				//printf("22: Grabbing\n");
			}
			//printf("Ajout 23\n");
			if (atoi(seglist[23].c_str()) > stat_success_the_king)
			{
				//printf("23: Condition remplie\n");
				stat_success_the_king = atoi(seglist[23].c_str());
				//printf("23: Conversion\n");
				str_stat_success_the_king = seglist[0].c_str();
				//printf("23: Grabbing\n");
			}
			if (atoi(seglist[24].c_str()) > stat_success_maso)
			{
				stat_success_maso = atoi(seglist[24].c_str());
				str_stat_success_maso = seglist[0].c_str();
			}
			if (atoi(seglist[25].c_str()) > stat_success_castle)
			{
				stat_success_castle = atoi(seglist[25].c_str());
				str_stat_success_castle = seglist[0].c_str();
			}
		}
		the_file.close(); //close the file object.
	}
	
	/*affichage*/
	printf("MEILLEURS STATISTIQUES :\n");
	printf(" [1] Nombre de jours survécus au maximum :	{%d} %s\n",stat_max_days,str_stat_max_days.c_str());
	printf(" [2] Défenses maximum mis en place :		{%d} %s\n",stat_max_def,str_stat_max_def.c_str());
	printf(" [3] Distance maximum parcourue :		{%d} %s\n",stat_max_killometers,str_stat_max_killometers.c_str());
	printf(" [4] Distance totale parcourue :		{%d} %s\n",stat_number_killometers,str_stat_number_killometers.c_str());
	printf(" [5] Nombre de drogues utilisées :		{%d} %s\n",stat_number_drugs,str_stat_number_drugs.c_str());
	printf(" [6] Nombre d'alcool ingéré :			{%d} %s\n",stat_number_alcohol,str_stat_number_alcohol.c_str());
	printf(" [7] Nombre de zombies tués :			{%d} %s\n",stat_number_kills,str_stat_number_kills.c_str());
	printf(" [8] Nombre de zombies tués à mains nus :	{%d} %s\n",stat_number_hardkills,str_stat_number_hardkills.c_str());
	printf(" [9] Nombre d'objets cassés :			{%d} %s\n",stat_number_brokenitems,str_stat_number_brokenitems.c_str());
	printf(" [10] Nombre de décorations :			{%d} %s\n",stat_number_decoration,str_stat_number_decoration.c_str());
	printf(" [11] Nombre de fabrications à l'atelier :	{%d} %s\n",stat_number_crafteditems,str_stat_number_crafteditems.c_str());
	printf(" [12] Mort(e) dehors :				{%d} %s\n",stat_number_death_outside,str_stat_number_death_outside.c_str());
	printf(" [13] Mort(e) dans le campement :		{%d} %s\n",stat_number_death_inside,str_stat_number_death_inside.c_str());
	printf(" [14] Mort(e) par dépendance :			{%d} %s\n",stat_number_death_drugs,str_stat_number_death_drugs.c_str());
	printf(" [15] Mort(e) désydraté(e) :			{%d} %s\n",stat_number_death_water,str_stat_number_death_water.c_str());
	printf(" [16] Mort(e) par maladie :			{%d} %s\n",stat_number_death_ill,str_stat_number_death_ill.c_str());
	printf(" [17] Mort(e) par suicide :			{%d} %s\n",stat_number_death_suicide,str_stat_number_death_suicide.c_str());
	printf("\nMEILLEURS SUCCEES:\n");
	printf(" [18] Terroriste : 				{%d} %s\n",stat_number_death_bomb,str_stat_number_death_bomb.c_str());
	printf(" [19] Massacre à la tronçonneuse :		{%d} %s\n",stat_success_chainsaw,str_stat_success_chainsaw.c_str());
	printf(" [20] Apprenti mécanicien :			{%d} %s\n",stat_success_cardoor,str_stat_success_cardoor.c_str());
	printf(" [21] Nourriture exotique :			{%d} %s\n",stat_success_vh,str_stat_success_vh.c_str());
	printf(" [22] Better when spicy :			{%d} %s\n",stat_success_spice,str_stat_success_spice.c_str());
	printf(" [23] The King Of Rock :			{%d} %s\n",stat_success_the_king,str_stat_success_the_king.c_str());
	printf(" [22] Masochiste :				{%d} %s\n",stat_success_maso,str_stat_success_maso.c_str());
	printf(" [23] Chateau construit :			{%d} %s\n",stat_success_castle,str_stat_success_castle.c_str());
	printf("\n [X] Retour au menu\n\n");
	
	encrypt();
	
	int choice;
	
	printf("Quel profil voulez vous regarder ?");
	fflush(stdin);
	printf("\n> ");
	scanf("%d",&choice);
	
	if (choice == 1) fstat_profile(str_stat_max_days);
	else if (choice == 2) fstat_profile(str_stat_max_def);
	else if (choice == 3) fstat_profile(str_stat_max_killometers);
	else if (choice == 4) fstat_profile(str_stat_number_killometers);
	else if (choice == 5) fstat_profile(str_stat_number_drugs);
	else if (choice == 6) fstat_profile(str_stat_number_alcohol);
	else if (choice == 7) fstat_profile(str_stat_number_kills);
	else if (choice == 8) fstat_profile(str_stat_number_hardkills);
	else if (choice == 9) fstat_profile(str_stat_number_brokenitems);
	else if (choice == 10) fstat_profile(str_stat_number_decoration);
	else if (choice == 11) fstat_profile(str_stat_number_crafteditems);
	else if (choice == 12) fstat_profile(str_stat_number_death_outside);
	else if (choice == 13) fstat_profile(str_stat_number_death_inside);
	else if (choice == 14) fstat_profile(str_stat_number_death_drugs);
	else if (choice == 15) fstat_profile(str_stat_number_death_water);
	else if (choice == 16) fstat_profile(str_stat_number_death_ill);
	else if (choice == 17) fstat_profile(str_stat_number_death_suicide);
	else if (choice == 18) fstat_profile(str_stat_number_death_bomb);
	else if (choice == 19) fstat_profile(str_stat_success_chainsaw);
	else if (choice == 20) fstat_profile(str_stat_success_cardoor);
	else if (choice == 21) fstat_profile(str_stat_success_vh);
	else if (choice == 22) fstat_profile(str_stat_success_spice);
	else if (choice == 23) fstat_profile(str_stat_success_the_king);
	else if (choice == 24) fstat_profile(str_stat_success_maso);
	else if (choice == 25) fstat_profile(str_stat_success_castle);
}


void Die4laugh::display_day0() // gere l'initialisation pseudo et menu
{
	bool done = false;
	char tmp[20];
	int choice;
	
	clean();
	
	if (username_input.compare("") == 0) // si le pseudo n'existe pas
	{
		while (!done)
		{
			printf("Entrez un nom d'utilisateur : ");
			scanf("%19s", tmp);
			username_input = tmp;
			fflush(stdin);
			clean();
			bool isAlphaNumeric = true;
			for (std::string::const_iterator s = username_input.begin(); s != username_input.end(); ++s)
				if (! isalnum(*s)) isAlphaNumeric = false;
			if (username_input.length() < 3 || username_input.length() > 16)
			{
				printf("\n\nLe nom d'utilisateur doit contenir entre 3 et 16 caractères.\n\n");
			}
			else if (!isAlphaNumeric)
			{
				printf("\n\nLe nom d'utilisateur ne peut contenir que des caractères alphanumérique.\n\n");
			}
			else
			{
				done = true;
			}
		}
		std::transform(username_input.begin(), username_input.end(), username_input.begin(), ::toupper); // met pseudo en maj
	}
	
	choice = 0;
	while (choice != 1)
	{
		clean();
		
		printf("$$$$$$$\\  $$$$$$\\ $$$$$$$$\\ $$\\   $$\\ $$\\        $$$$$$\\  $$\\   $$\\  $$$$$$\\  $$\\   $$\\ \n$$  __$$\\ \\_$$  _|$$  _____|$$ |  $$ |$$ |      $$  __$$\\ $$ |  $$ |$$  __$$\\ $$ |  $$ |\n$$ |  $$ |  $$ |  $$ |      $$ |  $$ |$$ |      $$ /  $$ |$$ |  $$ |$$ /  \\__|$$ |  $$ |\n$$ |  $$ |  $$ |  $$$$$\\    $$$$$$$$ |$$ |      $$$$$$$$ |$$ |  $$ |$$ |$$$$\\ $$$$$$$$ |\n$$ |  $$ |  $$ |  $$  __|   \\_____$$ |$$ |      $$  __$$ |$$ |  $$ |$$ |\\_$$ |$$  __$$ |\n$$ |  $$ |  $$ |  $$ |            $$ |$$ |      $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |\n$$$$$$$  |$$$$$$\\ $$$$$$$$\\       $$ |$$$$$$$$\\ $$ |  $$ |\\$$$$$$  |\\$$$$$$  |$$ |  $$ |\n\\_______/ \\______|\\________|      \\__|\\________|\\__|  \\__| \\______/  \\______/ \\__|  \\__|\n\n\n"); 


		printf("Bienvenue %s dans Die4laugh !\n\n",username_input.c_str());
		printf("[1] Jouer\n");
		printf("[2] Mon profil\n");
		printf("[3] Tableau des scores\n");
		
		printf("\n> ");
		fflush(stdin);
		scanf("%d",&choice);
		
		if (choice == 2)
		{
			fstat_profile(username_input);
		}
		else if (choice == 3)
		{
			//fstat_write();
			fstat_scoreboard();
		}
		
	}
	
	printf("test1"); wait_user();
	
	clean();
	printf("Die4laugh est un jeu de survie dans un monde hostile peuplé de zombies.\n\nPour survivre le plus longtemps, explorez le désert et fouillez les étendues désertiques pour y trouver\ndes armes, du matériel et de la nourriture. A chaque kilomètre, il est possible de procéder à des\nfouilles. Ces fouilles vous permettent de découvrir des objets que vous pourrez utiliser à votre guise.\n\nPrêt(e) à mourir ?\n\n");
	wait_user();
	
	printf("test2"); wait_user();
	
	fstat_get(username_input); // démarre avec les données du profil (sécurité)
	display_base();
}


std::string Die4laugh::print_item(int id, int type)
{
	std::string item_name, item_desc, item_type, item_prob, item_heavy, item_deco;
	item_heavy = "no";
	item_deco = "0";
	nb_items = 159;
	switch(id)
	{
		case 0:
			item_name = "";
			item_desc = "";
			item_type = "";
			item_prob = "0";
			break;
		case 1:
			item_name = "Doggy-Bag";
			item_desc = "Un vieux sac tout graisseux en papier qui doit bien contenir quelque chose à manger...\nNotez qu'il sent mauvais.";
			item_type = "2"; // container
			item_prob = "23";
			break;
		case 2:
			item_name = "Affaires de citoyen";
			item_desc = "C'est le petit container standard donné à tout citoyen dans les anciennes communautés.\nUn peu comme une pochette surprise.";
			item_type = "2";
			item_prob = "0";
			break;
		case 3:
			item_name = "Ration d'eau";
			item_desc = "La gourde vous permet de vous désaltérer. L'eau permet de récupérer son énergie et d'étancher la soif\n(pas de limitation par jour).";
			item_type = "1"; // ration d'eau
			item_prob = "0";
			break;
		case 4:
			item_name = "Ailerons de poulet entamés";
			item_desc = "Deux ailerons de poulet que quelqu'un a déja commencé à manger avant de les jeter ... Hmmm ...";
			item_type = "3"; // bouffe
			item_prob = "15";
			break;
		case 5:
			item_name = "Biscuit fades";
			item_desc = "Une tartelette qui sent vraiment fort... Pensez à quelque chose d'agréable pendant que vous l'avalerez.";
			item_type = "3";
			item_prob = "15";
			break;
		case 6:
			item_name = "Chewing-gums séchés";
			item_desc = "Une pleine poignée de chewing-gums tout séchés. En théorie, ça se mâche, mais ça ne s'avale pas.\nSeulement, dans cet enfer, vous n'êtes pas en position de faire le ou la difficile...";
			item_type = "3";
			item_prob = "15";
			break;
		case 7:
			item_name = "Jambon-beurre moisi";
			item_desc = "Un reste de casse-croute qui n'a d'appétissant que son souvenir...";
			item_type = "3";
			item_prob = "15";
			break;
		case 8:
			item_name = "Nouilles chinoises";
			item_desc = "Malgré les années passées dans le désert, ces nouilles chinoises ont toujours le même gout et le\nmême aspect.";
			item_type = "3";
			item_prob = "10";
			break;
		case 9:
			item_name = "Napolitains moisis";
			item_desc = "Une pâtisserie sous plastique : chocolat-vanille. Si vous agitez l'emballage, vous avez\nl'impression que quelque chose s'est liquéfié là-dedans...";
			item_type = "3";
			item_prob = "15";
			break;
		case 10:
			item_name = "Paquet de chips molles";
			item_desc = "Les chips de ce paquet sont molles et ont un goût de papier séché, mais on ne va pas faire\nle difficile... Un repas est un repas.";
			item_type = "3";
			item_prob = "15";
			break;
		case 11:
			item_name = "Petit-beurres rances";
			item_desc = "C'est sec et ça a un aspect rassi. Vous donneriez n'importe quoi pour faire passer le gout\nde ces biscuits...";
			item_type = "3";
			item_prob = "15";
			break;
		case 12:
			item_name = "Pims périmés";
			item_desc = "Une poignée de biscuits fourrés à la confiture de ... en fait vous l'ignorez... Peut-être un\nfruit. Mais ça a un gout de viande maintenant.";
			item_type = "3";
			item_prob = "15";
			break;
		case 13:
			item_name = "Lampe de chevet éteinte";
			item_desc = "C'est une jolie lampe de chevet, mais elle ne fonctionnera pas sans une pile neuve...";
			item_type = "4"; // 4 = assemblage
			item_prob = "8";
			break;
		case 14:
			item_name = "Lampe de chevet allumée";
			item_desc = "Avec une lampe de chevet, vous aurez moins peur la nuit et vous dormirez peut-être mieux ainsi.";
			item_type = "5"; // 5 = bonus d'energie au reveil
			item_prob = "0";
			item_deco = "3";
			break;
		case 15:
			item_name = "Pile";
			item_desc = "La pile sert à plein de truc. Mais ça se décharge souvent trop vite...";
			item_type = "6"; // rien
			item_prob = "53";
			break;
		case 16:
			item_name = "Produits pharmaceutiques";
			item_desc = "Un petit flacon et des produits mystérieux emballés sous plastique. Aucune idée de ce à quoi ça\npeut bien servir... Peut être qu'en le mélangeant avec un autre produit ?";
			item_type = "4";
			item_prob = "65";
			break;
		case 17:
			item_name = "Radio K7 éteint";
			item_desc = "Un ancien transistor avec une cassette de blues dedans. La radio elle-même est inutile car on ne\ncapte plus rien de nos jours.. Mais avoir un peu de musique chez soi pour couvrir les bruits terrifiants\nde la nuit est toujours réconfortant.";
			item_type = "4";
			item_prob = "10";
			break;
		case 18:
			item_name = "Radio K7 allumé";
			item_desc = "Un ancien transistor avec une cassette de blues dedans. La radio elle-même est inutile car on ne\ncapte plus rien de nos jours.. Mais avoir un peu de musique chez soi pour couvrir les bruits terrifiants\nde la nuit est toujours réconfortant.";
			item_type = "7"; // ajout de zombie au réveil
			item_prob = "0";
			item_deco = "2";
			break;
		case 19:
			item_name = "Boîte d'allumettes";
			item_desc = "Comme dit le dicton : on ne peut pas faire de feu de tout bois. Faîtes le mentir...";
			item_type = "4";
			item_prob = "20";
			break;
		case 20:
			item_name = "Stéroïdes Anabolisants";
			item_desc = "Cette drogue est idéale pour vous faire voir la vie en rose : plus de fatigue au prix de seulement\nquelques convulsions et d'un peu de bave aux lèvres... Gare à l'accoutumance !";
			item_type = "8"; // drugs1
			item_prob = "16";
			break;
		case 21:
			item_name = "Cutter";
			item_desc = "Ce petit couteau à lame rétractable disponible en coloris mauve ou fushia s'accordera très bien avec\nla couleur des viscères de vos ennemis. Pour peu qu'il traverse.";
			item_type = "9"; // weapon
			item_prob = "16";
			break;	
		case 22:
			item_name = "Cutter (cassé)";
			item_desc = "Ce petit couteau à lame rétractable disponible en coloris mauve ou fushia s'accordera très bien avec\nla couleur des viscères de vos ennemis. Pour peu qu'il traverse.";
			item_type = "10"; // broken weapon
			item_prob = "0";
			break;
		case 23:
			item_name = "Canif dérisoire";
			item_desc = "\"Canif [n.m.] : petit couteau de poche dont la lame se replie.\"Son porteur se replie aussi généralement s'il est intelligent.";
			item_type = "9"; // weapon
			item_prob = "16";
			break;	
		case 24:
			item_name = "Canif dérisoire (cassé)";
			item_desc = "\"Canif [n.m.] : petit couteau de poche dont la lame se replie.\"Son porteur se replie aussi généralement s'il est intelligent.";
			item_type = "10"; // broken weapon
			item_prob = "0";
			break;		
		case 25:
			item_name = "Jerrycan";
			item_desc = "Le Jerrycan contient plusieurs rations d'eau non-potable. Toutefois, il y a peut-être une façon de les purifier...";
			item_type = "6";
			item_prob = "25";
			break;
		case 26:
			item_name = "Micropur effervescent";
			item_desc = "Une capsule de produit désinfectant à mettre dans de l'eau pour la nettoyer. Avant, c'était utilisé pour récurer les toilettes. Vous imaginez aisément le goût de l'eau après... (ATTENTION: Le rendement de\nce produit est faible en comparaison d'un Purificateur industriel)";
			item_type = "4";
			item_prob = "20";
			break;
		case 27:
			item_name = "Clef à Molette";
			item_desc = "Avec une clé à Molette, vous pouvez au choix bricoler un objet ou détruire quelque chose. Pas forcement un objet d'ailleurs...";
			item_type = "9";
			item_prob = "14";
			break;
		case 28:
			item_name = "Clef à Molette (cassé)";
			item_desc = "Avec une clé à Molette, vous pouvez au choix bricoler un objet ou détruire quelque chose. Pas forcement un objet d'ailleurs...";
			item_type = "10";
			item_prob = "0";
			break;
		case 29:
			item_name = "Grosse chaîne rouillée";
			item_desc = "Cette vieille chaîne en fer est complètement distordue et n'a plus grande utilité... Mais on doit bien pouvoir étrangler quelqu'un avec.";
			item_type = "9";
			item_prob = "13";
			break;
		case 30:
			item_name = "Grosse chaîne rouillée (cassé)";
			item_desc = "Cette vieille chaîne en fer est complètement distordue et n'a plus grande utilité... Mais on doit bien pouvoir étrangler quelqu'un avec.";
			item_type = "10";
			item_prob = "0";
			break;
		case 31:
			item_name = "Machette";
			item_desc = "Au départ on se frayait un chemin avec. Ici aussi c'est le cas, mais la végétation est très vindicative et sinistrement bruyante...";
			item_type = "9";
			item_prob = "2";
			break;
		case 32:
			item_name = "Machette (cassé)";
			item_desc = "Au départ on se frayait un chemin avec. Ici aussi c'est le cas, mais la végétation est très vindicative et sinistrement bruyante...";
			item_type = "10";
			item_prob = "0";
			break;
		case 33:
			item_name = "Débris métalliques";
			item_desc = "Des bouts de ferrailles rouillées, du grillage, des vis...";
			item_type = "6";
			item_prob = "30";
			break;
		case 34:
			item_name = "Souche de bois pourrie";
			item_desc = "Une grosse souche de bois couverte de champignons visqueux.";
			item_type = "6";
			item_prob = "30";
			break;
		case 35:
			item_name = "Planche tordue";
			item_desc = "Une planche de bois complètement moisie mais encore à peu près solide...";
			item_type = "6";
			item_prob = "100";
			break;
		case 36:
			item_name = "Ferraille";
			item_desc = "Du métal... Un peu lourd, mais ça sert toujours !";
			item_type = "6";
			item_prob = "100";
			break;
		case 37:
			item_name = "Bandage rudimentaire";
			item_desc = "Ça sent mauvais, il y a des traces de moisissure, mais franchement, vous n'êtes pas en position de faire votre difficile. Ce bandage permet de panser une blessure.";
			item_type = "11"; // bandage
			item_prob = "4";
			break;
		case 38:
			item_name = "Os charnu";
			item_desc = "Un os avec encore un peu de viande autour... Bizarre. Ça a l'air encore frais en plus. Peut-être un animal tué pendant la nuit ?";
			item_type = "3"; 
			item_prob = "10";
			break;
		case 39:
			item_name = "Os humain fêlé";
			item_desc = "Un os (un tibia sans doute) tout séché que quelqu'un a rongé récemment semble-t-il... Ca doit pouvoir encore servir.";
			item_type = "9";
			item_prob = "1";
			break;
		case 40:
			item_name = "Os humain fêlé (cassé)";
			item_desc = "Un os (un tibia sans doute) tout séché que quelqu'un a rongé récemment semble-t-il... Ca doit pouvoir encore servir.";
			item_type = "10";
			item_prob = "0";
			break;
		case 41:
			item_name = "Paracétoïde 7mg";
			item_desc = "Un antipyrétique puissant capable d'enrayer n'importe quelle infection.\nLa notice précise : « ce médicament peut parfois provoquer quelques effets secondaire gênant (acné, vomissements, convulsions et mort violente) ».";
			item_type = "12"; // paracetoide
			item_prob = "8";
			break;
		case 42:
			item_name = "Structures métalliques";
			item_desc = "Du métal assemblé pour former une structure de soutien.";
			item_type = "6"; 
			item_prob = "20";
			item_heavy = "yes";
			break;
		case 43:
			item_name = "Poutre rafistolée";
			item_desc = "Un assemblage de bois qui forme une poutre de soutien relativement solide.";
			item_type = "6"; 
			item_prob = "20";
			item_heavy = "yes";
			break;
		case 44:
			item_name = "Buche en bon état";
			item_desc = "Une belle buche qui pourrait tout à fait servir de tabouret à la maison. Après tout... C'est mieux que rien.";
			item_type = "6";
			item_prob = "5";
			break;
		case 45:
			item_name = "Composant électronique";
			item_desc = "Une vieille plaque probablement sortie d'un poste de radio ou d'un quelconque gadget électrique.";
			item_type = "6";
			item_prob = "5";
			break;
		case 46:
			item_name = "Courroie";
			item_desc = "Une courroie... Ca doit sûrement servir à quelque chose.";
			item_type = "6";
			item_prob = "5";
			break;
		case 47:
			item_name = "Explosifs bruts";
			item_desc = "Boum !";
			item_type = "17"; // explosifs
			item_prob = "1";
			break;
		case 48:
			item_name = "Détonateur compact";
			item_desc = "Un dispositif compact qui peut faire exploser une petite charge d'explosif...";
			item_type = "6";
			item_prob = "10";
			break;
		case 49:
			item_name = "Fragments de tôle";
			item_desc = "Des morceaux de tôle qui ne demandent qu'à servir de protection dans votre maison...\nPour peu que vous les assembliez correctement.";
			item_type = "6";
			item_prob = "13";
			item_heavy = "yes";
			break;
		case 50:
			item_name = "Poignée de vis et écrous";
			item_desc = "Certaines pièces sont rouillées, d'autres sont couvertes de mousse verdâtre,\nmais elles ont toutes au moins le mérite de continuer à remplir leur rôle. Plus ou moins.";
			item_type = "4";
			item_prob = "16";
			break;
		case 51:
			item_name = "Rustine";
			item_desc = "Toujours pratique pour coller des choses ensemble.";
			item_type = "5";
			item_prob = "34";
			break;
		case 52:
			item_name = "Tube de cuivre";
			item_desc = "Un tube en cuivre, un peu sale et dont l'utilité vous échappe...";
			item_type = "6";
			item_prob = "30";
			break;
		case 53:
			item_name = "Sac de ciment";
			item_desc = "Un gros sac de ciment de qualité très moyenne...\nUne fois dilué dans de l'eau, ça sèche rapidement pour donner du béton particulièrement résistant !";
			item_type = "4";
			item_prob = "10";
			item_heavy = "yes";
			break;
		case 54:
			item_name = "Moteur incomplet";
			item_desc = "C'est un genre de petit moteur plein de traces d'huile brulée et matières calcinées indéfinissables. Par contre, il pèse son poids et il semble lui manquer pas mal de pièces...";
			item_type = "4";
			item_prob = "1";
			item_heavy = "yes";
			break;
		case 55:
			item_name = "Poudre Super-Fuzz";
			item_desc = "Selon le époques, cette poudre a tour à tour servi de détonateur pour divers pièces d'artillerie, puis comme\ndrogue bas de gamme pour citoyen en manque avant d'être utilisée comme ingrédient principal dans les feux d'artifice.\nDans les 3 cas, beaucoup de gens n'y ont pas survécu.";
			item_type = "6";
			item_prob = "4";
			item_deco = "5";
			break;
		case 56:
			item_name = "Tube de lancement Floush";
			item_desc = "Plusieurs longs tubes en plastique sans grand intérêt.";
			item_type = "6";
			item_prob = "1";
			item_heavy = "yes";
			break;
		case 57:
			item_name = "Lentille convexe";
			item_desc = "Cette lentille en bon état n'attend qu'un peu de votre ingéniosité pour être utilisé efficacement.";
			item_type = "4";
			item_prob = "10";
			break;
		case 58:
			item_name = "Diode Lazer";
			item_desc = "Un composant électronique d'une époque révolue, dans l'état on peut s'en servir de juda, même si on ne voit pas à travers.";
			item_type = "6";
			item_prob = "10";
			break;
		case 59:
			item_name = "Sachet d'herbe fraîche";
			item_desc = "Puisqu'on vous dit que c'est de l'herbe banale, il y a surement une autre utilité à cette herbe qu'une simple cigarette roulée.";
			item_type = "6";
			item_prob = "3";
			break;
		case 60:
			item_name = "Bidon d'huile vide";
			item_desc = "On trouve de temps en temps des bidons d'huile vides dans le désert, souvent accompagné d'un cadavre.\nQuand est ce que les citoyens comprendront que l'huile, ça ne se boit pas ...";
			item_type = "6";
			item_prob = "3";
			break;
		case 61:
			item_name = "Morceau de caisse";
			item_desc = "Un vieil assemblage de planches qui était utilisé pour fermer une grosse caisse, autrefois.\nCa pourrait bien servir de défense, si seulement vous trouviez de quoi le consolider.";
			item_type = "4";
			item_prob = "10";
			item_heavy = "yes";
			break;
		case 62:
			item_name = "Pavés de béton informes";
			item_desc = "Ça ne ressemble pas le moins du monde à des briques, mais c'est en béton armé et ça doit pouvoir servir de défenses chez soi...\nAu pire, jetez-les sur des zombies, ça sera un peu comme une manifestation.";
			item_type = "13";
			item_prob = "2";
			item_heavy = "yes";
			break;
		case 63:
			item_name = "Plaque de bois solide";
			item_desc = "Ce gros couvercle de caisse fera bien l'affaire pour bloquer une brèche du campement.";
			item_type = "13";
			item_prob = "1";
			item_heavy = "yes";
			break;
		case 64:
			item_name = "Plaque de tôle";
			item_desc = "Rien ne vaut une plaque de tôle rouillée pour empêcher les zombies de vous atteindre...";
			item_type = "13";
			item_prob = "1";
			item_heavy = "yes";
			break;
		case 65:
			item_name = "Table Järpen";
			item_desc = "Entièrement assemblée avec des élastiques et des picots de bois, cette table fera sûrement très joli dans votre “salon”.\nEt mise à la verticale, elle pourrait bien aussi vous sauver la vie, un soir.";
			item_type = "13";
			item_prob = "5";
			item_heavy = "yes";
			item_deco = "3";
			break;
		case 66:
			item_name = "Tréteau";
			item_desc = "Un tréteau relativement solide qui devrait s'avérer utile pour consolider les défenses du campement.";
			item_type = "13";
			item_prob = "10";
			item_heavy = "yes";
			break;
		case 67:
			item_name = "Vieille porte";
			item_desc = "C'est une porte en bois. Modèle classique, autrefois blanche, mais couverte de terre aujourd'hui. Ça pourra toujours servir...";
			item_type = "13";
			item_prob = "10";
			item_heavy = "yes";
			break;
		case 68:
			item_name = "Torche";
			item_desc = "Elle doit bien brûler quelques heures... Ça sera toujours ça de plus pour éloigner les zombies.";
			item_type = "13";
			item_prob = "0";
			break;
		case 69:
			item_name = "Torche consumée";
			item_desc = "Un vieux bout de bois calciné qui ne vous servira sûrement plus à grand chose...";
			item_type = "9";
			item_prob = "0";
			break;	
		case 70:
			item_name = "Torche consumée (cassé)";
			item_desc = "Un vieux bout de bois calciné qui ne vous servira sûrement plus à grand chose...";
			item_type = "10";
			item_prob = "0";
			break;
		case 71:
			item_name = "Tournevis";
			item_desc = "Le tournevis visse et dévisse, il vous permet de réparer des choses et à la limite, d'ouvrir des boîtes de conserve. En dernier ressort, plantez-le dans une tête: ça pourrait bien vous sauver la vie...";
			item_type = "9";
			item_prob = "16";
			break;
		case 72:
			item_name = "Tournevis (cassé)";
			item_desc = "Le tournevis visse et dévisse, il vous permet de réparer des choses et à la limite, d'ouvrir des boîtes de conserve. En dernier ressort, plantez-le dans une tête: ça pourrait bien vous sauver la vie...";
			item_type = "9";
			item_prob = "0";
			break;
		case 73:
			item_name = "Meuble en kit";
			item_desc = "Un meuble en pièces détachées, difficile à identifier...";
			item_type = "6";
			item_prob = "15";
			item_heavy = "yes";
			break;
		case 74:
			item_name = "Viande indéfinissable";
			item_desc = "Vous êtes quasiment certain que cette chose molle et visqueuse peut se manger. En tous cas, ça ne sent pas mauvais et ça ne bouge pas.";
			item_type = "3";
			item_prob = "10";
			break;
		case 75:
			item_name = "Viande humaine";
			item_desc = "Allez on oublie ce qu'on vient de manger et on passe à autre chose.";
			item_type = "3";
			item_prob = "5";
			break;
		case 76:
			item_name = "Portière de voiture incomplète";
			item_desc = "Cette grosse portière fera parfaitement office de bouclier improvisé dans le désert,\nquand il s'agira de passer en force dans des hordes de cadavres avides de votre délicieux cerveau.";
			item_type = "4";
			item_prob = "2";
			item_heavy = "yes";
			break;
		case 77:
			item_name = "Portière de voiture";
			item_desc = "Cette grosse portière fera parfaitement office de bouclier improvisé dans le désert,\nquand il s'agira de passer en force dans des hordes de cadavres avides de votre délicieux cerveau.";
			item_type = "13";
			item_prob = "1";
			item_heavy = "yes";
			break;
		case 78:
			item_name = "Moteur";
			item_desc = "C'est un genre de petit moteur plein de traces d'huile brulée et matières calcinées indéfinissables. Par contre, il pèse son poids et il semble lui manquer pas mal de pièces...";
			item_type = "6";
			item_prob = "0";
			item_heavy = "yes";
			break;
		case 79:
			item_name = "Sac supplémentaire";
			item_desc = "Idéal pour vos randonnées entre amis, il vous permet de stocker plus de souvenirs: biologiques, nucléaires ou autres.";
			item_type = "14"; // slot supplementaire
			item_prob = "4";
			break;
		case 80:
			item_name = "Ceinture à poches";
			item_desc = "Cette ceinture vous permet de disposer d'1 emplacement de sac à dos supplémentaire.";
			item_type = "14";
			item_prob = "2";
			break;
		case 81:
			item_name = "Sac super-pratique";
			item_desc = "Le compagnon de voyage idéal ! Poche latérale, étanche, renforcé aux épaules, auto-massant pendant la marche\net avec un joli logo “Desert Addict” chromé.";
			item_type = "14";
			item_prob = "1";
			break;
		case 82:
			item_name = "Caddie";
			item_desc = "On l'appelle “Le Caddie”. Personne ne sait à quoi ça pouvait bien servir à part mettre des objets dedans,\nmais le nom inscrit dessus était rigolo. Bon, par contre, ça ne roule pas bien dans le sable.";
			item_type = "14";
			item_prob = "0";
			break;
		case 83:
			item_name = "Caddie bancal";
			item_desc = "Un genre de gros chariot métallique, mais l'un des essieux est manquant. Il faudrait quelque chose pour le remplacer...";
			item_type = "4";
			item_prob = "5";
			item_heavy = "yes";
			break;
		case 84:
			item_name = "Bobine de fil de fer";
			item_desc = "Attention à ne pas s’emmêler avec, on ne voudrait pas avoir à vous couper les doigts pour vous en libérer.";
			item_type = "4";
			item_prob = "5";
			break;
		case 85:
			item_name = "Mine Antipersonnelle";
			item_desc = "On trouve encore des mines dans le désert, en général, ce sont plus les gens imprudents que les zombies qui marchent dessus.";
			item_type = "15"; // mine
			item_prob = "0";
			break;	
		case 86:
			item_name = "Cyanure";
			item_desc = "Quand rien ne va, une petite capsule de cyanure, un grand verre d’eau et on attend que ça passe avec un sourire apaisé.";
			item_type = "16"; // cyanure
			item_prob = "5";
			break;	
		case 87:
			item_name = "Fusil d'assaut";
			item_desc = "Une version modifiée du AK-47, plus compacte, probablement destiné à un usage \"civil\"... La chasse à la Galinette Cendrée diront certains.";
			item_type = "4";
			item_prob = "1";
			item_deco = "15";
			break;	
		case 88:
			item_name = "Revolver";
			item_desc = "Une arme de poing : le modèle P-22, très réputé pour sa fiabilité et sa grande précision. Mais ça ne sert strictement à rien sans munition...";
			item_type = "4";
			item_prob = "5";
			item_deco = "5";
			break;
		case 89:
			item_name = "Appareil électronique en panne";
			item_desc = "Un vieil appareil électro-ménager impossible à identifier. Peut-être qu'en le démontant vous pourriez obtenir quelque chose ? ";
			item_type = "6";
			item_prob = "10";
			break;
		case 90:
			item_name = "Matelas";
			item_desc = "ZZzzzz... Grincement... ZZzzzz... Grincement...";
			item_type = "13";
			item_prob = "10";
			item_heavy = "yes";
			break;
		case 91:
			item_name = "Médicament sans étiquette";
			item_desc = "Une boîte de médicaments dont l'étiquette est complètement effacée.\nLes cachets dedans sont pour la plupart moisis, mais vous en trouver quelques uns qui soient encore “consommables”.\nMais êtes-vous suffisamment mal pour pouvoir avaler ça ?";
			item_type = "18"; // mse
			item_prob = "20";
			break;
		case 92:
			item_name = "Piqure de calmant";
			item_desc = "Allez calmez-vous... Vous en verrez bien d'autres.";
			item_type = "19"; // piqure
			item_prob = "10";
			break;
		case 93:
			item_name = "Hydratone";
			item_desc = "Pratique, l'Hydratone tient dans la poche et peut étancher votre soif quelques minutes après l'ingestion.\nToutefois, elle ne retire PAS les effets de la fatigue et ne régénère PAS l'énergie.";
			item_type = "20"; // hydratone
			item_prob = "20";
			break;
		case 94:
			item_name = "Betapropine 5mg périmée";
			item_desc = "Ce petit cachet a un effet pour le moins mystérieux... Sur la boîte, il est écrit:\n\"ne pas donner à un testeur de moins de 18 ans\". Étrange.";
			item_type = "18";
			item_prob = "10";
			break;
		case 95:
			item_name = "Twinoïde 500mg";
			item_desc = "Un concentré de caféïne, de théine, de diverses drogues chimiques et de testicules de taureau broyées.\nLa drogue idéale pour les coups de fouets en fin de journée, ou quand il s'agit de fuir face à une horde de zombies qui en veulent à votre foie.";
			item_type = "21"; // twinoid
			item_prob = "6";
			break;
		case 96:
			item_name = "Poignée de cartouches";
			item_desc = "La clé d'accès pour des armes de qualité.";
			item_type = "6";
			item_prob = "1";
			break;
		case 98:
			item_name = "Vodka Marinostov";
			item_desc = "Un coup de fouet très violent pour oublier la fatigue (et récupérer toute son énergie)... 85° d'alcool pur, avec diverses choses vaguement organiques qui flottent dedans. Santé camarade !";
			item_type = "22"; // alcool
			item_prob = "10";
			break;
		case 99:
			item_name = "Debout-les-morts";
			item_desc = "Un cocktail inventé par un certain Joey si on en croit l'étiquette. Mélange de rhum, de piment rouge et de whiskey, avec un doigt mariné qui flotte entre deux eaux...";
			item_type = "22";
			item_prob = "5";
			break;
		case 100:
			item_name = "Melon d'intestin";
			item_desc = "Habituellement le melon d'intestin pousse dans le ventre des cadavres, au niveau du gros colon. Il semblerait pourtant que votre potager en ait donné de très jolis... Peut être avez vous cultivé sur un vieux cimetière indien ?";
			item_type = "3";
			item_prob = "1";
			break;
		case 101:
			item_name = "Légume suspect";
			item_desc = "Un genre de... légume... Difficile à dire ce qui a essayé de pousser comme ça, mais le principal c'est que ça semble comestible. Ou pas.";
			item_type = "3";
			item_prob = "1";
			break;
		case 102:
			item_name = "Steak appétissant";
			item_desc = "C'est un peu élastique et ça sent même le poisson... On se demande bien ce que ça peut être,\nmais c'est surement plein de vitamines (et pas d'autres choses, espérez-vous).";
			item_type = "3";
			item_prob = "9";
			break;
		case 103:
			item_name = "Nouilles chinoises épicées";
			item_desc = "Des nouilles copieusement assaisonnées ! Hmm, ça va vous changer de vos repas à base de chose en décomposition.";
			item_type = "3";
			item_prob = "0";
			break;
		case 104:
			item_name = "Poignée de bonbons";
			item_desc = "Vous avez une petite larme à l'oeil en contemplant cette poignée de délicieux bonbons...";
			item_type = "3";
			item_prob = "1";
			break;
		case 105:
			item_name = "Bon plat fait-maison";
			item_desc = "En apparence, ça n'est guère mieux qu'une ration quotidienne. Mais en réalité ça a très bon goût et ça nourrit bien.";
			item_type = "3";
			item_prob = "0";
			break;
		case 106:
			item_name = "Chamallows calcinés";
			item_desc = "Quelques chamallows tout durcis et qui sentent le rat mort. Maintenant qu'ils sont complètement calcinés, on Peut dire qu'ils sont mangeables.\nOn Peut même dire qu'ils sont appétissants, quand on y réfléchit bien...";
			item_type = "3";
			item_prob = "0";
			break;
		case 107:
			item_name = "Epices fortes";
			item_desc = "Un petit sachet d'épices...";
			item_type = "4";
			item_prob = "5";
			break;
		case 108: 
			item_name = "Tronçonneuse incomplète";
			item_desc = "Un outil hautement amusant, mais il semblerait qu'il manque une courroie et quelques babioles pour qu'elle fonctionne...";
			item_type = "4";
			item_prob = "0";
			item_heavy = "yes";
			break;
		case 109:
			item_name = "Chamallows séchés";
			item_desc = "Quelques chamallows tout durcis et qui sentent le rat mort. C'est complètement immangeable tel quel...";
			item_type = "4";
			item_prob = "3";
			break;
		case 110:
			item_name = "Boîte-déjeuner";
			item_desc = "A défaut d'un vrai repas autour d'une table, avec des couverts et des amis, vous avez cette boite-déjeuner spécial Apocalypse...";
			item_type = "2";
			item_prob = "5";
			break;
		case 111:
			item_name = "Caisse de nourriture";
			item_desc = "Une odeur abominable de moisi et de charogne émane de cette caisse... Mais vous êtes presque sûr(e) qu'elle contient un petit quelque chose de comestible.\nDu moins vous espérez.";
			item_type = "2";
			item_prob = "10";
			item_heavy = "yes";
			break;
		case 112:
			item_name = "Caisse de matériel";
			item_desc = "Cette vieille caisse en bois doit contenir des babioles utiles.";
			item_type = "2";
			item_prob = "20";
			item_heavy = "yes";
			break;
		case 113:
			item_name = "Boîte en métal";
			item_desc = "Une vieille boîte métallique couverte de rouille et complètement cabossée. Qui sait ce qu'elle peut bien contenir ?";
			item_type = "2";
			item_prob = "15";
			item_heavy = "yes";
			break;
		case 114:
			item_name = "Gros coffre en métal";
			item_desc = "C'est particulièrement lourd et ça contient sûrement quelque chose de précieux ... Reste à trouver un endroit pour l'ouvrir.";
			item_type = "6";
			item_prob = "2";
			item_heavy = "yes";
			break;
		case 115:
			item_name = "Tronçonneuse éteinte";
			item_desc = "Avec ça, vous allez faire un vrai massacre. Mais sachez qu'on en ressort peut-être victorieux mais pas tout à fait indemne...\nCette machine infernale a été modifiée et fonctionne (chose incroyable) avec une simple pile !";
			item_type = "4";
			item_prob = "0";
			item_heavy = "yes";
			break;
		case 116:
			item_name = "Tronçonneuse";
			item_desc = "Avec ça, vous allez faire un vrai massacre. Mais sachez qu'on en ressort peut-être victorieux mais pas tout à fait indemne...\nCette machine infernale a été modifiée et fonctionne (chose incroyable) avec une simple pile !";
			item_type = "23"; // arme rechargable
			item_prob = "0";
			item_heavy = "yes";
			break;
		case 117:
			item_name = "Scie à métaux abîmée";
			item_desc = "Une scie qui pourrait être pratique, si elle était rafistolée.";
			item_type = "4";
			item_prob = "3";
			break;
		case 118:
			item_name = "Scie à métaux";
			item_desc = "Une scie dont les dents sont pour la plupart tordues, mais qui fera bien l'affaire pour couper des choses.\nSi seulement il y avait un endroit adapté...";
			item_type = "6";
			item_prob = "0";
			break;
		case 119:
			item_name = "Télescope";
			item_desc = "Cette lentille en bon état n'attend qu'un peu de votre ingéniosité pour être utilisé efficacement.";
			item_type = "4";
			item_prob = "0";
			break;
		case 120:
			item_name = "Mécanisme";
			item_desc = "Ce mécanisme devait faire partie d'un ensemble plus gros : une machine ou un véhicule quelconque... Il ne sert plus à rien tel quel. ";
			item_type = "6";
			item_prob = "10";
			break;
		case 121:
			item_name = "Liasse de billets";
			item_desc = "Une liasse de papiers teintés et quelques rondelles de cuivre qui servaient autrefois de monnaie d'échange.\nAujourd'hui, tout ce qui ne se mange pas ou ne peut pas s'injecter dans le sang n'a aucune véritable valeur...";
			item_type = "6";
			item_prob = "5";
			item_deco = "7";
			break;
		case 122:
			item_name = "Paillasson";
			item_desc = "Ça vous changera d'essuyer vos chaussures sur quelque chose de propre pour une fois.";
			item_type = "6";
			item_prob = "5";
			item_deco = "6";
			break;
		case 123:
			item_name = "Tapis persan";
			item_desc = "Ça vous évitera de voir toutes ces choses horribles qui jonchent le sol de votre maison...";
			item_type = "6";
			item_prob = "2";
			item_deco = "10";
			break;
		case 124:
			item_name = "Unité centrale";
			item_desc = "Cette vieille boîte en ferraille contenait tout un tas de composants électroniques auparavant. Elle ne semble plus avoir aucune utilité maintenant...";
			item_type = "9";
			item_prob = "5";
			item_deco = "2";
			item_heavy = "yes";
			break;
		case 125:
			item_name = "Unité centrale (cassé)";
			item_desc = "Cette vieille boîte en ferraille contenait tout un tas de composants électroniques auparavant. Elle ne semble plus avoir aucune utilité maintenant...";
			item_type = "9";
			item_prob = "0";
			item_deco = "2";
			item_heavy = "yes";
			break;
		case 126:
			item_name = "Four cancérigène";
			item_desc = "Les légendes racontent que la technologie à Micro-Ondes serait l'une des raisons du déclin de la civilisation. Certains disent même que l'existence même des morts-vivants n'y serait pas étrangère.";
			item_type = "9";
			item_prob = "7";
			item_deco = "2";
			item_heavy = "yes";
			break;
		case 127:
			item_name = "Four cancérigène (cassé)";
			item_desc = "Les légendes racontent que la technologie à Micro-Ondes serait l'une des raisons du déclin de la civilisation. Certains disent même que l'existence même des morts-vivants n'y serait pas étrangère.";
			item_type = "9";
			item_prob = "0";
			item_deco = "2";
			item_heavy = "yes";
			break;
		case 128:
			item_name = "Réfrigérateur d'étudiant";
			item_desc = "Une grosse machine pour garder les choses fraiches et les empêcher de pourrir trop vite. Elle ne fonctionne plus mais on doit bien pouvoir en tirer quelque chose.";
			item_type = "9";
			item_prob = "5";
			item_deco = "2";
			item_heavy = "yes";
			break;
		case 129:
			item_name = "Réfrigérateur d'étudiant (cassé)";
			item_desc = "Une grosse machine pour garder les choses fraiches et les empêcher de pourrir trop vite. Elle ne fonctionne plus mais on doit bien pouvoir en tirer quelque chose.";
			item_type = "9";
			item_prob = "0";
			item_deco = "2";
			item_heavy = "yes";
			break;
		case 130:
			item_name = "Vieille machine à laver";
			item_desc = "Une antique machine à laver le linge, artéfact d'une antique civilisation qui plaçait la propreté au dessus de toute autre préoccupation. Ca vous fait bien rigoler aujourd'hui";
			item_type = "9";
			item_prob = "7";
			item_deco = "2";
			item_heavy = "yes";
			break;
		case 131:
			item_name = "Vieille machine à laver (cassé)";
			item_desc = "Une antique machine à laver le linge, artéfact d'une antique civilisation qui plaçait la propreté au dessus de toute autre préoccupation. Ca vous fait bien rigoler aujourd'hui";
			item_type = "9";
			item_prob = "0";
			item_deco = "2";
			item_heavy = "yes";
			break;
		case 132:
			item_name = "Compilation du King";
			item_desc = "Prêt à bouger votre corps suintant au rythm du rock n' roll ? Cette compilation du légendaire king of rock va mettre le feu à la scène !";
			item_type = "4";
			item_prob = "2";
			item_deco = "8";
			break;
		case 133:
			item_name = "Figurine de Chuck";
			item_desc = "L'esprit du grand Chuck habite cette figurine, rien ne peux lui arriver, et même après votre mort, elle restera là, sans craindre les hordes";
			item_type = "6";
			item_prob = "2";
			item_deco = "15";
			break;
		case 134:
			item_name = "Caisse de feux d'artifice";
			item_desc = "Cette boite contient tout un attirail de produits chimiques hautement toxiques aux noms évocateurs, tels que : Sodium-Fuzz, Carbopotassium Bling Bling ou Rainbow Lithium Cyanurisé";
			item_type = "6";
			item_prob = "3";
			item_deco = "2";
			item_heavy = "yes";
			break;
		case 135:
			item_name = "Teddy n'Ours";
			item_desc = "Un petit doudou en peluche qui a dû faire le bonheur d'un enfant... Un jour...";
			item_type = "6";
			item_prob = "0";
			item_deco = "15";
			break;
		case 136:
			item_name = "Petite chaine HiFi éteinte";
			item_desc = "Un chaîne HiFi \"petit budget\", mais on ne va pas faire les difficiles... Dommage qu'il lui manque une pile pour fonctionner..";
			item_type = "4";
			item_prob = "2";
			item_deco = "7";
			item_heavy = "yes";
			break;
		case 137:
			item_name = "Petite chaine HiFi";
			item_desc = "Accordez-vous un peu de détente en écoutant les derniers succès : Zombies IYA ou Peur Bleue Au Fond à Gauche.";
			item_type = "6";
			item_prob = "0";
			item_deco = "10";
			item_heavy = "yes";
			break;
		case 138:
			item_name = "Chaîne Hi-Fi Rock n'Roll";
			item_desc = "Combiné à un CD du King, vous vous réveillerez avec une pêche d'enfer tous les matins.";
			item_type = "6";
			item_prob = "0";
			item_deco = "15";
			item_heavy = "yes";
			break;
		case 139:
			item_name = "Chaise Jmâ Tedësseri";
			item_desc = "Une banale chaise de fabrication suédoise. On peut taper des gens avec, mais ca fonctionnera mieux si c'est simplement rangé en sécurité chez soi...";
			item_type = "9";
			item_prob = "7";
			item_deco = "2";
			item_heavy = "yes";
			break;
		case 140:
			item_name = "Chaise Jmâ Tedësseri (cassé)";
			item_desc = "Une banale chaise de fabrication suédoise. On peut taper des gens avec, mais ca fonctionnera mieux si c'est simplement rangé en sécurité chez soi...";
			item_type = "9";
			item_prob = "0";
			item_deco = "2";
			item_heavy = "yes";
			break;
		case 141:
			item_name = "Rocking Chair";
			item_desc = "ZZzzzz... Grincement... ZZzzzz... Grincement...";
			item_type = "6";
			item_prob = "5";
			item_deco = "5";
			item_heavy = "yes";
			break;
		case 142:
			item_name = "Sport-Elec (éteint)";
			item_desc = "La version militaire d'un gadget pour se muscler à coups de décharges électriques. Un message est inscrit : \"Appartient à Aymeric, à utiliser pour avoir la pêche ou pour causer de sévères lésions\".";
			item_type = "4";
			item_prob = "7";
			break;
		case 143:
			item_name = "Sport-Elec (chargé)";
			item_desc = "La version militaire d'un gadget pour se muscler à coups de décharges électriques. Un message est inscrit : \"Appartient à Aymeric, à utiliser pour avoir la pêche ou pour causer de sévères lésions\".";
			item_type = "24"; // sport elec
			item_prob = "0";
			break;
		case 144:
			item_name = "Petit manche vibrant (éteint)";
			item_desc = "Il vibre, vous titille et vous chatouille et vous fait oublier tous vos soucis pendant quelques instants.";
			item_type = "4";
			item_prob = "4";
			break;
		case 145:
			item_name = "Petit manche vibrant";
			item_desc = "Il vibre, vous titille et vous chatouille et vous fait oublier tous vos soucis pendant quelques instants.";
			item_type = "25"; // pmv
			item_prob = "0";
			break;
		case 146:
			item_name = "Teddy n'Ours";
			item_desc = "Un petit doudou en peluche qui a dû faire le bonheur d'un enfant... Un jour...";
			item_type = "26"; // ours
			item_prob = "3";
			item_deco = "4";
			break;
		case 147:
			item_name = "Plat fait-maison douteux";
			item_desc = "Des ingrédients combinés un peu n'importe comment, une ébauche de cuisson et un assaisonnement au sable du désert. Hmmm...";
			item_type = "3";
			item_prob = "0";
			break;
		case 148:
			item_name = "Fusil d'assaut (chargé)";
			item_desc = "Une version modifiée du AK-47, plus compacte, probablement destiné à un usage \"civil\"... La chasse à la Galinette Cendrée diront certains.";
			item_type = "23";
			item_prob = "0";
			item_deco = "15";
			break;	
		case 149:
			item_name = "Revolver (chargé)";
			item_desc = "Une arme de poing : le modèle P-22, très réputé pour sa fiabilité et sa grande précision. Mais ça ne sert strictement à rien sans munition...";
			item_type = "23";
			item_prob = "1";
			item_deco = "5";
			break;
		case 150:
			item_name = "Morceau de grillage";
			item_desc = "Une petite partie d'une clôture grillagée, rouillée et abîmée";
			item_type = "6";
			item_prob = "20";
			item_deco = "0";
			break;
		case 151:
			item_name = "Brico'Facile";
			item_desc = "Un petit kit à usage unique pour réparer tout et n'importe quoi. Il contient quelques outils basiques, des pièces plastique de recharge et un guide du petit bricoleur imprimé en 7 langues.";
			item_type = "27"; // reparation
			item_prob = "8";
			item_deco = "0";
			break;
		case 152:
			item_name = "Kit de bricolage abimé";
			item_desc = "Cette boîte en ferraille contient tout le nécessaire de base pour remettre en état à peu près n'importe quoi. Sauf vos voisins morts.";
			item_type = "6";
			item_prob = "3";
			break;
		case 153:
			item_name = "Kit de bricolage";
			item_desc = "Cette boîte en ferraille contient tout le nécessaire de base pour remettre en état à peu près n'importe quoi. Sauf vos voisins morts.";
			item_type = "27";
			item_prob = "3";
			break;
		case 154:
			item_name = "Lance-Pile 1-PDTG";
			item_desc = "Imaginé avec les moyens du bord, le Lance-Pile 1-PDTG permet, par un savant recyclage, de transformer des piles en projectiles perforants.";
			item_type = "4";
			item_prob = "8";
			break;
		case 155:
			item_name = "Lance-Pile 1-PDTG (chargé)";
			item_desc = "Imaginé avec les moyens du bord, le Lance-Pile 1-PDTG permet, par un savant recyclage, de transformer des piles en projectiles perforants.";
			item_type = "23";
			item_prob = "0";
			break;
		case 156:
			item_name = "Couteau à dents";
			item_desc = "\"Skinner, Buck, Bowie... Dans tous les cas ça coupe.\" Note : Le Couteau à dents est utile pour ouvrir certaines boîtes.";
			item_type = "9";
			item_prob = "6";
			break;
		case 157:
			item_name = "Couteau à dents (cassé)";
			item_desc = "Skinner, Buck, Bowie… Dans tous les cas ça coupe. » Note : Le Couteau à dents est utile pour ouvrir certaines boîtes.";
			item_type = "10";
			item_prob = "0";
			break;
		case 158:
			item_name = "Couteau suisse";
			item_desc = "Le Couteau Suisse pourra sans soucis vous dépanner pour tous les petits travaux manuels, sauf peut-être découper une horde de mort-vivants.";
			item_type = "9";
			item_prob = "16";
			break;
		case 159:
			item_name = "Couteau suisse (cassé)";
			item_desc = "Le Couteau Suisse pourra sans soucis vous dépanner pour tous les petits travaux manuels, sauf peut-être découper une horde de mort-vivants.";
			item_type = "10";
			item_prob = "0";
			break;
	}
	if (type == 0)
	{
 	    return(item_name);
	}
	if (type == 1)
	{
 	    return(item_desc);
	}
	if (type == 2)
	{
 	    return(item_type);
	}
	if (type == 3)
	{
		return(item_prob);
	}
	if (type == 4)
	{
		return(item_heavy);
	}
	if (type == 5)
	{
		return(item_deco);
	}
}


void Die4laugh::reset_ground()
{
	int i;
	for (i=0; i<ground_size; i++)
	{
		ground[i] = 0;
	}
}


void Die4laugh::display_states()
{
	if (energy <= 0)
	{
		printf("   Fatigué(e)");
	}
	if (no_drugs == true)
	{
		printf("   Clair(e)");
	}
	if (water_day == true)
	{
		printf("   Désaltéré(e)");
	}
	if (food_day == true)
	{
		printf("   Rassasié(e)");
	}
	if (drug_day == true)
	{
		printf("   Drogué(e)");
	}
	if (dependant == true)
	{
		printf("   Dépendant(e)");
	}
	if (thirst == true)
	{
		printf("   Soif");
	}
	if (big_thirst == 1)
	{
		printf("   Désydrathé(e)");
	}
	if (injury == true)
	{
		printf("   Bléssé(e)");
	}
	if (ill == true)
	{
		printf("   Infecté(e)");
	}
	if (meds == true)
	{
		printf("   Immunisé(e)");
	}
	if (alcohol == true)
	{
		printf("   Ivre");
	}
	if (hangover == true)
	{
		printf("   Gueule de bois");
	}
	if (terror == true)
	{
		printf("   Terreur");
	}
}


void Die4laugh::display_bag()
{
	int i;
	bool empty = true;
	for (i=0; i<bag_size; i++)
	{
		if (bag[i] != 0)
		{
			empty = false;
		}
	}
	if (empty)
	{
		printf(" Vide !\n");
	}
	else
	{
		for (i=0; i<bag_size; i++)
		{
			printf("[%d] - %s\n",i+1,print_item(bag[i],0).c_str());
		}
	}
}


void Die4laugh::display_ground() // make_my_ground_firstindex()
{
	int i;
	bool empty = true;
	
	if (ground[0] == 0)
	{
		printf(" Pas d'objets au sol.\n");
	}
	else
	{
		for (i=0; i<ground_size && ground_first[i] != 0; i++)
		{
			if (ground_index[i] > 1)
			{
				printf("[%d] - x%d %s ",i+bag_size+1,ground_index[i],print_item(ground_first[i],0).c_str());
			}
			else
			{
				printf("[%d] - %s ",i+bag_size+1,print_item(ground_first[i],0).c_str());
			}
			if (print_item(ground_first[i],2).compare("13") == 0 && location.compare("Campement") == 0) // afficher def +5
				printf("(+5 def) ");
			//printf("%s %d\n",print_item(ground_first[i],0).c_str(),atoi(print_item(ground_first[i],5).c_str()));
			if (atoi(print_item(ground_first[i],5).c_str()) > 0 && location.compare("Campement") == 0) // afficher deco
				printf("(+%s déco) ",print_item(ground_first[i],5).c_str());
			printf("\n");
		}
	}
}


void Die4laugh::make_my_ground_firstindex()
{
	int i, j;
	bool already_exist;
	
	for (i=0; i<ground_size; i++) // reset des tableaux
	{
		ground_first[i] = 0;
		ground_index[i] = 0;
	}
	
	// on crée le tableau des premiers éléments
	i = 0;
	while (ground[i] != 0)
	{
		already_exist = false;
		j = 0;
		while (ground_first[j] != 0)
		{
			if (ground[i] == ground_first[j]) // si il a déjà été rajouté
			{
				already_exist = true; // pour ne pas rajouter 2x dans ground_first
				ground_index[j]++;
				break;
			}
			j++;
		}
		if (!already_exist)
		{
			for (j=0; j<ground_size; j++) // append in ground_first
			{
				if (ground_first[j] == 0)
				{
					ground_first[j] = ground[i];
					ground_index[j] = 1;
					break;
				}
			}
		}
		i++;
	}
}


void Die4laugh::reload_location()
{
	int number, location_alea, i;
	nb_locations = 20;
	location_alea = 0;
	
	monsters = ((rand()%15 + days*3)/5) - rand()%8 + rand()%(kilometers/7+1);
	
	if (kilometers_building[kilometers] == -1) // premiere fois à ce kilometre, génération de la zone
	{
		if (rand()%5 != 0) // 4 chance sur 5
		{
			kilometers_building[kilometers] = 0;
		}
		else
		{
			location_alea = rand()%nb_locations+1;
			kilometers_building[kilometers] = location_alea;
		}
	
		for (i=0; i<=ground_size; i++) // génération du sol
		{
			kilometers_save[kilometers][i] = 0;
		}
	}
	
	if (kilometers_building[kilometers] == 0) // désert
	{
		if (kilometers_exhausted[kilometers] >= 13) // zone épuisé
		{
			location = "Désert (zone épuisé)";
		}
		else
		{
			location = "Désert...";
		}
	}
	else // batiment
	{
		monsters = ((rand()%15 + days*3)/5) - rand()%7 + rand()%(kilometers/5+1);
		switch(kilometers_building[kilometers]) // actualiser nb_locations pour DEV nouveau bat
		{
			case 1:
				location = "Petite maison";
				break;
			case 2:
				location = "Puits abandonné";
				break;
			case 3:
				location = "Centrale hydrolique";
				break;
			case 4:
				location = "Camion en panne";
				break;
			case 5:
				location = "Petit bois obscur";
				break;
			case 6:
				location = "Carcasses de voitures";
				break;
			case 7:
				location = "Carrière effondrée";
				break;
			case 8:
				location = "Caveau familial";
				break;
			case 9:
				location = "Ancien Velib";
				break;
			case 10:
				location = "Carlingue d'avion";
				break;
			case 11:
				location = "Chantiers à l'abandon";
				break;
			case 12:
				location = "Meubles KIELA";
				break;
			case 13:
				location = "Route barrée";
				break;
			case 14:
				location = "Ambulance";
				break;
			case 15:
				location = "Villa délabrée";
				break;
			case 16:
				location = "Supermarché pillé";
				break;
			case 17:
				location = "Bar miteux";
				break;
			case 18:
				location = "BricoTout";
				break;
			case 19:
				location = "Armurerie'N'Massy";
				break;
			case 20:
				location = "Stand de fête foraine";
				break;
		}
	}
	
	if (monsters < 0) monsters = 0;
	stuck_f(); // etre coincé par les zombies ou pas
}


int Die4laugh::open(int * items, int size)
{
	int item;
	item = items[rand()%size];
	return item;
}


int Die4laugh::check_bag(int id, int avoid_id) // (searsch,occurence to avoid)
{
	int i, position;
	for (i=0; i<bag_size; i++)
	{
		if (bag[i] == id && i != avoid_id)
		{
			return(i); // return id of item in bag
		}
	}
	return(-1);
}


void Die4laugh::use_item(int number)
{
	int i;
	int item;
	int final_item; //pour les containers
	int need_item, need_item2, need_item3, need_item4, need_item5; // pour les assemblages
	
	item = number - 1;
	
	clean();
	
	if (print_item(bag[item],2).compare("1") == 0) // eau
	{
		if (water_day == true && thirst == false && big_thirst == false)
		{
			printf("Vous avez déjà bu une fois aujourd'hui : la seule utilité de l'eau pour cette journée sera\nd'étancher votre soif plus tard.");
		}
		else
		{
			if (energy >= energy_max && thirst == false && big_thirst == false)
			{
				printf("Vous n'avez pas besoin de boire pour le moment: vous n'êtes pas fatigué(e) et vous disposez de toute\nvotre énergie.");
			}
			else
			{
				printf("Vous avalez d'une traite votre ration d'eau... Ça fait du bien !");
				if (water_day == true)
				{
					printf("\n\nCependant vous ne récupérer pas votre énergie, vous avez déjà bu aujourd'hui.");
				}
				else
				{
					if (big_thirst == false)
					{
						energy = energy_max;
					}
				}
				bag[item] = 0;
				sort_empty_racism(bag,bag_size);
				water_day = true;
				if (big_thirst == true)
				{
					printf("\n\nIl semblerait que vous aviez tellement soif que vous ne récupérez pas d'enérgie !");
					big_thirst = false;
					thirst = true;
					water_day = false;
				}
				else if (thirst == true)
				{
					thirst = false;
				}
			}
		}
	}
	
	else if (print_item(bag[item],2).compare("2") == 0) // containers
	{
		bool do_you_have_weapon = false;
		bool do_you_need_weapon = false;
		for (i=0; i<bag_size; i++) if (print_item(bag[i],2).compare("9") == 0) do_you_have_weapon = true;
		if (bag[item] == 1) // doggy-bag
		{
			int possible_items[9] = {4,5,6,7,8,9,10,11,12};
			final_item = open(possible_items, 9);
		}
		if (bag[item] == 2) // affaire citoyen
		{
			int possible_items[6] = {3,13,15,16,17,19};
			final_item = open(possible_items, 6);
		}
		if (bag[item] == 110) // boite dejeuner
		{
			do_you_need_weapon = true;
			int possible_items[4] = {100,102,103,104};
			final_item = open(possible_items, 4);
		}
		if (bag[item] == 111) // caisse nourriture
		{
			do_you_need_weapon = true;
			int possible_items[4] = {100,102,103,104};
			final_item = open(possible_items, 4);
		}
		if (bag[item] == 112) // caisse materiel
		{
			do_you_need_weapon = true;
			int possible_items[6] = {47,15,50,16,51,52};
			final_item = open(possible_items, 6);
		}
		if (bag[item] == 113) // boite en metal
		{
			do_you_need_weapon = true;
			int possible_items[6] = {95,19,98,99,20,15};
			final_item = open(possible_items, 6);
		}
		
		if (do_you_need_weapon == true && do_you_have_weapon == false)
		{
			printf("Il vous faudrait un objet ou quelque chose pour ouvrir ce truc.");
		}
		else
		{
			printf("Vous avez ouvert %s, vous trouvez %s à l'intérieur.",print_item(bag[item],0).c_str(),print_item(final_item,0).c_str());
			bag[item] = final_item;
			sort_empty_racism(bag,bag_size);
		}
	}
	
	else if (print_item(bag[item],2).compare("3") == 0) // bouffe
	{
		if (food_day == true)
		{
			printf("Vous ne pouvez manger qu'une seule fois par jour.");
		}
		else
		{
			if (energy >= energy_max)
			{
				printf("Vous n'avez pas besoin de manger pour le moment: vous n'êtes pas fatigué(e) et vous disposez de toute votre énergie.\n");
			}
			else
			{
				food_day = true;
				if (bag[item] == 38 && meds == false && ill == false && rand()%2 == 0) // os charnu
				{
					printf("\nVous commencez à avoir mal au ventre...\n");
					ill = true;
					
					bag[item] = 39;
				}
				else if (bag[item] == 102 || bag[item] == 103 || bag[item] == 104 || bag[item] == 105 || bag[item] == 106 || bag[item] == 100)
				{
					printf("Une fois n'est pas coutume, vous vous faîtes plaisir en avalant %s. Ca change des rations quotidiennes infectes...\nVous reprenez du poil de la bête.",print_item(bag[item],0).c_str());
					energy = energy_max+1;
					sort_empty_racism(bag,bag_size);
					bag[item] = 0;
				}
				else
				{
					printf("Ca a un goût vraiment bizarre, difficile à définir. Mais ça remplit son rôle : remplir votre estomac...\n");
					energy = energy_max;
					sort_empty_racism(bag,bag_size);
					bag[item] = 0;
				}
				if (bag[item] == 38 || bag[item] == 75)
					stat_success_vh++;
			}
		}
	}
	
	else if (print_item(bag[item],2).compare("4") == 0) // assemblage
	{
		if (bag[item] == 13) // lampe de chevet
		{
		 need_item = check_bag(15,-1);
		 if (need_item != -1) // si il existe
		 {
		 	 printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(14,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
		 	 bag[item] = 14;
			 bag[need_item] = 0;
		 	 sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s.",print_item(15,0).c_str());
		 }
		}
		else if (bag[item] == 16) // PP
		{
		 need_item = check_bag(16,item);
		 if (need_item != -1)
		 {
		 	 int possible_items[5] = {20,91,92,93,94};
		 	 bag[item] = open(possible_items,5);
		 	 printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(bag[item],0).c_str(),print_item(16,0).c_str(),print_item(16,0).c_str());
			 bag[need_item] = 0;
		 	 sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s.",print_item(16,0).c_str());
		 }
		}
		else if (bag[item] == 17) // radio K7
		{
			need_item = check_bag(15,-1);
			if (need_item != -1)
			{
				printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(18,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
				bag[item] = 18;
				bag[need_item] = 0;
				sort_empty_racism(bag,bag_size);
			}
			else
			{
				printf("Impossible, vous avez besoin de %s.",print_item(15,0).c_str());
			}
		}
		else if (bag[item] == 26) // micropur effervescent
		{
		 need_item = check_bag(25,-1);
		 if (need_item != -1)
		 {
		 	 printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(3,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
		 	 bag[item] = 0;
			 bag[need_item] = 0;
			 for (i=0; i<=rand()%3+1; i++)
			 {
			 	add_item(3);
			 }
		 	 sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s.",print_item(25,0).c_str());
		 }
		}
		else if (bag[item] == 53) // sac de ciment
		{
		 need_item = check_bag(3,-1);
		 if (need_item != -1)
		 {
		 	 printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(62,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
		 	 bag[item] = 62;
			 bag[need_item] = 0;
		 	 sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s.",print_item(3,0).c_str());
		 }
		}
		else if (bag[item] == 61) // plaque de bois
		{
		 need_item = check_bag(35,-1);
		 if (need_item != -1)
		 {
		 	 printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(63,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
		 	 bag[item] = 63;
			 bag[need_item] = 0;
		 	 sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s.",print_item(35,0).c_str());
		 }
		}
		else if (bag[item] == 19) // torche
		{
		 need_item = check_bag(34,-1);
		 if (need_item != -1)
		 {
		 	 printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(68,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
		 	 bag[item] = 68;
			 bag[need_item] = 0;
		 	 sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s.",print_item(34,0).c_str());
		 }
		}
		else if (bag[item] == 76) // portiere
		{
			need_item = check_bag(51,-1);
			need_item2 = check_bag(36,-1);
			need_item3 = check_bag(50,-1);
			if (need_item != -1 && need_item2 != -1 && need_item3 != -1)
			{
				printf("Vous avez fabriqué %s en combinant %s, %s, %s et %s.",print_item(77,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str(),print_item(bag[need_item2],0).c_str(),print_item(bag[need_item3],0).c_str());
				bag[item] = 77;
				bag[need_item] = 0;
				bag[need_item2] = 0;
				bag[need_item3] = 0;
				sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size);
				stat_success_cardoor++;
			}
			else
			{
				printf("Impossible, vous avez besoin de %s, %s et %s.",print_item(51,0).c_str(),print_item(36,0).c_str(),print_item(50,0).c_str());
			}
		}
		else if (bag[item] == 54) // moteur
		{
		 need_item = check_bag(36,-1);
		 need_item2 = check_bag(39,-1);
		 need_item3 = check_bag(48,-1);
		 need_item4 = check_bag(50,-1);
		 need_item5 = check_bag(51,-1);
		 if (need_item != -1 && need_item2 != -1 && need_item3 != -1 && need_item4 != -1 && need_item5 != -1)
		 {
		 	 printf("Vous avez fabriqué %s en combinant %s, %s, %s, %s, %s et %s.",print_item(78,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str(),print_item(bag[need_item2],0).c_str(),print_item(bag[need_item3],0).c_str(),print_item(bag[need_item4],0).c_str(),print_item(bag[need_item5],0).c_str());
		 	 bag[item] = 78;
			 bag[need_item] = 0;
			 bag[need_item2] = 0;
			 bag[need_item3] = 0;
			 bag[need_item4] = 0;
			 bag[need_item5] = 0;
		 	 sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s, %s, %s, %s et %s.",print_item(36,0).c_str(),print_item(39,0).c_str(),print_item(48,0).c_str(),print_item(50,0).c_str(),print_item(51,0).c_str());
		 }
		}
		else if (bag[item] == 83) // cadie
		{
		 need_item = check_bag(36,-1);
		 need_item2 = check_bag(51,-1);
		 need_item3 = check_bag(52,-1);
		 if (need_item != -1 && need_item2 != -1 && need_item3 != -1)
		 {
		 	 printf("Vous avez fabriqué %s en combinant %s, %s, %s et %s.",print_item(82,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str(),print_item(bag[need_item2],0).c_str(),print_item(bag[need_item3],0).c_str());
		 	 bag[item] = 82;
			 bag[need_item] = 0;
			 bag[need_item2] = 0;
			 bag[need_item3] = 0;
		 	 sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s, %s et %s.",print_item(36,0).c_str(),print_item(51,0).c_str(),print_item(52,0).c_str());
		 }
		}
		else if (bag[item] == 84) // mine antipersonelle
		{
		 need_item = check_bag(47,-1);
		 need_item2 = check_bag(48,-1);
		 need_item3 = check_bag(50,-1);
		 need_item4 = check_bag(51,-1);
		 if (need_item != -1 && need_item2 != -1 && need_item3 != -1 && need_item4 != -1)
		 {
		 	 printf("Vous avez fabriqué %s en combinant %s, %s, %s, %s et %s.",print_item(85,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str(),print_item(bag[need_item2],0).c_str(),print_item(bag[need_item3],0).c_str(),print_item(bag[need_item4],0).c_str());
		 	 bag[item] = 85;
			 bag[need_item] = 0;
			 bag[need_item2] = 0;
			 bag[need_item3] = 0;
			 bag[need_item4] = 0;
		 	 sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s, %s, %s et %s.",print_item(47,0).c_str(),print_item(48,0).c_str(),print_item(50,0).c_str(),print_item(51,0).c_str());
		 }
		}
		else if (bag[item] == 88) // revolver
		{
		 need_item = check_bag(96,-1);
		 if (need_item != -1)
		 {
		 	 printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(149,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
		 	 bag[item] = 149;
			 bag[need_item] = 0;
		 	 sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s.",print_item(96,0).c_str());
		 }
		}
		else if (bag[item] == 87) // fusil d'assaut
		{
		 need_item = check_bag(148,-1);
		 if (need_item != -1)
		 {
		 	 printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(148,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
		 	 bag[item] = 148;
			 bag[need_item] = 0;
		 	 sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s.",print_item(96,0).c_str());
		 }
		}
		else if (bag[item] == 107) // epices
		{
			need_item = check_bag(8,-1);
			need_item2 = check_bag(3,-1);
			if (need_item != -1 && need_item2 != -1)
			{
				printf("Vous avez fabriqué %s en combinant %s, %s et %s.",print_item(103,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str(),print_item(bag[need_item2],0).c_str());
				bag[item] = 103;
				bag[need_item] = 0;
				bag[need_item2] = 0;
				sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size);
				stat_success_spice++;
			}
			else
			{
				printf("Impossible, vous avez besoin de %s et %s.",print_item(8,0).c_str(),print_item(3,0).c_str());
			}
		}
		else if (bag[item] == 109) // chamallow
		{
			need_item = check_bag(68,-1);
			if (need_item != -1)
			{
				printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(106,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
				bag[item] = 106;
				//bag[need_item] = 0; // on garde la torche
				sort_empty_racism(bag,bag_size);
			}
			else
			{
			printf("Impossible, vous avez besoin de %s.",print_item(68,0).c_str());
			}
		}
		else if (bag[item] == 108) // tronconneuse incomplète
		{
			need_item = check_bag(46,-1);
			need_item2 = check_bag(50,-1);
			need_item3 = check_bag(51,-1);
			need_item4 = check_bag(78,-1);
			if (need_item != -1 && need_item2 != -1 && need_item3 != -1 && need_item4 != -1)
			{
				printf("Vous avez fabriqué %s en combinant %s, %s, %s, %s et %s.",print_item(115,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str(),print_item(bag[need_item2],0).c_str(),print_item(bag[need_item3],0).c_str(),print_item(bag[need_item4],0).c_str());
				bag[item] = 115;
				bag[need_item] = 0;
				bag[need_item2] = 0;
				bag[need_item3] = 0;
				bag[need_item4] = 0;
				sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size);
				stat_success_chainsaw++;
			}
			else
			{
				printf("Impossible, vous avez besoin de %s, %s, %s, et %s.",print_item(46,0).c_str(),print_item(50,0).c_str(),print_item(51,0).c_str(),print_item(78,0).c_str());
			}
		}
		else if (bag[item] == 115) // tronconneuse éteinte
		{
			need_item = check_bag(15,-1);
			if (need_item != -1)
			{
				printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(116,0).c_str(),print_item(bag[item],115).c_str(),print_item(bag[need_item],15).c_str());
				bag[item] = 116;
				bag[need_item] = 0;
				sort_empty_racism(bag,bag_size);
			}
			else
			{
				printf("Impossible, vous avez besoin de %s.",print_item(15,0).c_str());
			}
		}
		else if (bag[item] == 117) // scie a metaux
		{
			need_item = check_bag(50,-1);
			need_item2 = check_bag(51,-1);
			need_item3 = check_bag(71,-1);
			if (need_item != -1 && need_item2 != -1 && need_item3 != -1)
			{
				printf("Vous avez fabriqué %s en combinant %s, %s, %s et %s.",print_item(118,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str(),print_item(bag[need_item2],0).c_str(),print_item(bag[need_item3],0).c_str());
				bag[item] = 118;
				bag[need_item] = 0;
				bag[need_item2] = 0;
				sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size);
			}
			else
			{
				printf("Impossible, vous avez besoin de %s, %s et %s.",print_item(50,0).c_str(),print_item(51,0).c_str(),print_item(71,0).c_str());
			}
		}
		else if (bag[item] == 57) // téléscope
		{
			need_item = check_bag(52,-1);
			if (need_item != -1)
			{
				printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(119,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
				bag[item] = 119;
				bag[need_item] = 0;
				sort_empty_racism(bag,bag_size);
			}
			else
			{
				printf("Impossible, vous avez besoin de %s.",print_item(52,0).c_str());
			}
		}
		else if (bag[item] == 136) // chaine hifi eteinte
		{
			need_item = check_bag(15,-1);
			need_item2 = check_bag(45,-1);
			if (need_item != -1 && need_item2 != -1)
			{
				printf("Vous avez fabriqué %s en combinant %s, %s et %s.",print_item(137,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str(),print_item(bag[need_item2],0).c_str());
				bag[item] = 137;
				bag[need_item] = 0;
				bag[need_item2] = 0;
				sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size);
			}
			else
			{
				printf("Impossible, vous avez besoin de %s et %s.",print_item(15,0).c_str(),print_item(45,0).c_str());
			}
		}
		else if (bag[item] == 132) // compilation du king
		{
			need_item = check_bag(137,-1);
			if (need_item != -1)
			{
				system("start https://www.youtube.com/watch?v=T1Ond-OwgU8");
				stat_success_the_king++;
				clean();
				printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(138,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
				bag[item] = 138;
				bag[need_item] = 0;
				sort_empty_racism(bag,bag_size);
			}
			else
			{
				printf("Impossible, vous avez besoin de %s.",print_item(137,0).c_str());
			}
		}
		else if (bag[item] == 142) // sport elec
		{
			need_item = check_bag(15,-1);
			if (need_item != -1)
			{
				printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(143,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
				bag[item] = 143;
				bag[need_item] = 0;
				sort_empty_racism(bag,bag_size);
			}
			else
			{
				printf("Impossible, vous avez besoin de %s.",print_item(15,0).c_str());
			}
		}
		else if (bag[item] == 144) // pmv
		{
			need_item = check_bag(15,-1);
			if (need_item != -1)
			{
				printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(145,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
				bag[item] = 145;
				bag[need_item] = 0;
				sort_empty_racism(bag,bag_size);
			}
			else
			{
				printf("Impossible, vous avez besoin de %s.",print_item(15,0).c_str());
			}
		}
		else if (bag[item] == 154) // lance pile
		{
		 need_item = check_bag(15,-1);
		 if (need_item != -1) // si il existe
		 {
		 	 printf("Vous avez fabriqué %s en combinant %s et %s.",print_item(155,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
		 	 bag[item] = 155;
			 bag[need_item] = 0;
		 	 sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s.",print_item(15,0).c_str());
		 }
		}
	
	}
	
	else if (print_item(bag[item],2).compare("8") == 0) // drugs1
	{
		if (energy >= energy_max)
		{
		 printf("Vous n'avez pas besoin de cela pour le moment...");
		}
		else
		{
			printf("Les effets de la drogue ne tardent pas à se faire sentir: nausée, tremblements, sueurs froides... Mais au moins,\nça vous donne un bon coup de fouet. N'en abusez pas !");
			energy = energy_max;
			bag[item] = 0;
			sort_empty_racism(bag,bag_size);
			no_drugs = false;
			if (drug_day == false)
			{
				drug_day = true;
			}
			else if (dependant == false)
			{
				printf("\n\nMauvaise nouvelle ! Vous devenez par la même occasion dépendant(e) ! Vous devrez dorénavant consommer au\nmoins une drogue par jour ou mourir !");
				dependant = true;
			}
			stat_number_drugs++;
		}
	}
	
	else if (print_item(bag[item],2).compare("9") == 0) // weapons
	{
		int prob_b, prob_k, killnb, broken_item;
		int random_prob;
		
		if (bag[item] == 21) {prob_b = 70; prob_k = 70; killnb=1; broken_item=22;} // cutter
		else if (bag[item] == 23) {prob_b = 20; prob_k = 75; killnb=1; broken_item=24;} // canif dérisoire
		else if (bag[item] == 27) {prob_b = 8; prob_k = 45; killnb=1; broken_item=28;} // clé a molette
		else if (bag[item] == 29) {prob_b = 15; prob_k = 70; killnb=1; broken_item=30;} // chaine
		else if (bag[item] == 31) {prob_b = 10; prob_k = 75; killnb=2; broken_item=32;} // machette
		else if (bag[item] == 39) {prob_b = 40; prob_k = 70; killnb=1; broken_item=40;} // os felee
		else if (bag[item] == 69) {prob_b = 80; prob_k = 25; killnb=1; broken_item=70;} // torche consumée
		else if (bag[item] == 71) {prob_b = 60; prob_k = 15; killnb=1; broken_item=72;} // tournevis
		else if (bag[item] == 124) {prob_b = 70; prob_k = 60; killnb=1; broken_item=125;} // unité centrale
		else if (bag[item] == 126) {prob_b = 40; prob_k = 80; killnb=1; broken_item=127;} // four
		else if (bag[item] == 128) {prob_b = 20; prob_k = 70; killnb=1; broken_item=129;} // frigo
		else if (bag[item] == 130) {prob_b = 20; prob_k = 75; killnb=1; broken_item=131;} // machine a laver
		else if (bag[item] == 139) {prob_b = 40; prob_k = 60; killnb=1; broken_item=140;} // chaise
		else if (bag[item] == 156) {prob_b = 10; prob_k = 80; killnb=1; broken_item=157;} // couteau a dents
		else if (bag[item] == 158) {prob_b = 25; prob_k = 75; killnb=1; broken_item=159;} // couteaux suisse
		
		
		if (killnb>monsters) killnb = monsters;
		
		if (location.compare("Campement") == 0 || monsters <= 0)
		{
			printf("Vous n'avez pas besoin de faire cela pour le moment.");
		}
		else
		{
			random_prob = rand()%100;
			if (random_prob > prob_k)
			{
				if (killnb > monsters) killnb = monsters;
				monsters = monsters-killnb; // kill
				if (monsters < 0) monsters = 0;
				printf("Vous avez éliminé %d zombies en utilisant %s. Ha ! Ha ! Un peu plus de chair étalée... Ca soulage de supprimer du zombie de temps en temps.\n\n",killnb,print_item(bag[item],0).c_str());
				stat_number_kills = stat_number_kills + killnb;
			}
			else
			{
				printf("Vous avez frappé de toutes vos forces sur le bipode, malheureusement il ne s'est pas écroulé sur vos coups.\n");
			}
			random_prob = rand()%100;
			if (random_prob < prob_b)
			{
				bag[item] = broken_item; // item cassé
				printf("\n\nToutefois : votre arme a été cassée sous le choc.");
				stat_number_brokenitems++;
			}
		}
	}
	
	else if (print_item(bag[item],2).compare("11") == 0) // bandage
	{
		if (convalescent == true)
		{
			printf("Vous ne pouvez pas appliquer un nouveau bandage, vous êtes déjà en état de convalescence.\n");
		}
		else
		{
			printf("Vous nettoyez cette vilaine blessure et appliquer le bandage, mieux vaut se reposer maintenant.\n");
			convalescent = true;
			injury = false;
			energy_max = 6;
			bag[item] = 0;
			sort_empty_racism(bag,bag_size);
		}
	}
	
	else if (print_item(bag[item],2).compare("12") == 0) // drugs2 paracetoide
	{
		stat_number_drugs++;
		bag[item] = 0;
		sort_empty_racism(bag,bag_size);
		meds = true;
		ill = false;
		no_drugs = false;
		printf("Ce médicament a renforcé votre organisme : vous ne subirez pas d''infection. Cet effet se dissipera le lendemain.\nNote : cet effet ne protège pas des infections provoquées par une blessure non-traitée");
		 if (drug_day == false)
		 {
		 	drug_day = true;
		 }
		 else
		 {
			printf("\n\nMauvaise nouvelle ! Vous devenez par la même occasion dépendant(e) !\nVous devrez dorénavant consommer au moins une drogue par jour ou mourir !");
		 	dependant = true;
		 }
	}
	
	else if (print_item(bag[item],2).compare("16") == 0) // cyanure
	{
		bag[item] = 0;
		sort_empty_racism(bag,bag_size);
		death(8);
	}
	
	else if (print_item(bag[item],2).compare("17") == 0) // explosif
	{
		int killnb;
		int random_prob;
		
		if (bag[item] = 47) killnb=rand()%6+1; // explosifs bruts
		
		if (killnb>monsters) killnb = monsters;
		
		if (location.compare("Campement") == 0 || monsters <= 0)
		{
			printf("Vous n'avez pas besoin de faire cela pour le moment.");
		}
		else
		{
			if (killnb > monsters) killnb = monsters;
			monsters = monsters-killnb; // kill
			if (monsters < 0) monsters = 0;
			printf("Boom ! Vous avez éliminé %d zombies en utilisant %s. Ha ! Ha ! Un peu plus de chair étalée... Ca soulage de supprimer du zombie de temps en temps.\n\n",killnb,print_item(22,0).c_str());
			stat_number_kills = stat_number_kills + killnb;
		}
	}

	else if (print_item(bag[item],2).compare("18") == 0) // drugs3
	{
		int rand_number = rand()%4;
		stat_number_drugs++;

		if (rand_number == 0)
		{
			printf("Les effets de la drogue ne tardent pas à se faire sentir: nausée, tremblements, sueurs froides... Mais au moins,\nça vous donne un bon coup de fouet. N'en abusez pas !");
			energy = energy_max;
		}
		else if (rand_number == 1)
		{
			printf("Vous regrettez rapidement d'avoir avalé %s...\nCe produit se révèle être un puissant stéroïde pour animaux (le genre que l'on donnait aux chevaux de course).\nVous récupérez votre énergie, mais vous devenez immédiatement Dépendant(e) aux drogues !",print_item(item,0).c_str());
			energy = energy_max+1;
			dependant = true;
		}
		else if (rand_number == 2)
		{
			printf("Vous gobez %s. Après plusieurs minutes, vous sentez une douleur sourde vous serrer le crâne et votre nez se met à saigner.\nRien d'insupportable, mais rien de positif non plus...",print_item(item,0).c_str());
		}
		else if (rand_number == 3)
		{
			printf("Quelques secondes à peine après, c'est la panique... Sueurs froids, sentiment de persécution...\nVous vous recroquevillez, le souffle coupé, en espérant que ça passe... mais ça ne passe pas...",print_item(item,0).c_str());
			terror = true;
		}
		bag[item] = 0;
		sort_empty_racism(bag,bag_size);
		no_drugs = false;
		if (drug_day == false)
		{
			drug_day = true;
		}
		else if (dependant == false)
		{
			printf("\n\nMauvaise nouvelle ! Vous devenez par la même occasion dépendant(e) ! Vous devrez dorénavant consommer au\nmoins une drogue par jour ou mourir !");
			dependant = true;
		}
	}
	
	else if (print_item(bag[item],2).compare("19") == 0) // drugs4
	{
		stat_number_drugs++;
		if (terror == false)
		{
			printf("Vous utilisez %s, mais ce produit ne semble avoir aucun effet immédiat notable... Peut-être n'en aviez vous pas vraiment besoin ?\n",print_item(item,0).c_str());
		}
		else
		{
			printf("La drogue fait rapidement effet... Tout vous semble soudainement plus calme, plus serein...\nMême les évènements atroces des derniers jours vous semblent maintenant sans importance... Ca va mieux.\n");
			terror = false;
		}
		bag[item] = 0;
		sort_empty_racism(bag,bag_size);
		no_drugs = false;
		if (drug_day == false)
		{
			drug_day = true;
		}
		else if (dependant == false)
		{
			printf("\n\nMauvaise nouvelle ! Vous devenez par la même occasion dépendant(e) ! Vous devrez dorénavant consommer au\nmoins une drogue par jour ou mourir !");
			dependant = true;
		}
	}
	
	else if (print_item(bag[item],2).compare("20") == 0) // drugs5
	{
		stat_number_drugs++;
		if (thirst == false && big_thirst == false)
		{
			printf("Vous utilisez %s, mais ce produit ne semble avoir aucun effet immédiat notable... Peut-être n'en aviez vous pas vraiment besoin ?\n",print_item(item,0).c_str());
		}
		else
		{
			printf("Vous avalez votre pillule...\nQuelques instants après, la sensation de soif finit par s'estomper...");
			if (big_thirst == true)
			{
				big_thirst = false;
				thirst = true;
			}
			else if (thirst == true)
			{
				thirst = false;
			}
		}
		bag[item] = 0;
		sort_empty_racism(bag,bag_size);
		no_drugs = false;
		if (drug_day == false)
		{
			drug_day = true;
		}
		else if (dependant == false)
		{
			printf("\n\nMauvaise nouvelle ! Vous devenez par la même occasion dépendant(e) ! Vous devrez dorénavant consommer au\nmoins une drogue par jour ou mourir !");
			dependant = true;
		}
	}
	
	else if (print_item(bag[item],2).compare("21") == 0) // drugs6
	{
		stat_number_drugs++;
		printf("C'est pas tous les jours qu'on peut avaler de la câme de qualité.\nLes effets sont quand même là: nausée, tremblements, sueurs froides...\nEn bien plus intense que pour une drogue normale (bonus d'énergie)...\nN'en abusez pas !");
		energy = energy_max+2;
		bag[item] = 0;
		sort_empty_racism(bag,bag_size);
		no_drugs = false;
		if (drug_day == false)
		{
			drug_day = true;
		}
		else if (dependant == false)
		{
			printf("\n\nMauvaise nouvelle ! Vous devenez par la même occasion dépendant(e) ! Vous devrez dorénavant consommer au\nmoins une drogue par jour ou mourir !");
			dependant = true;
		}
	}

	else if (print_item(bag[item],2).compare("22") == 0) // alcool
	{
		if (alcohol == true)
		{
			printf("Vous ne pouvez boire de l'alcool qu'une seule fois par jour.");
		}
		else if (hangover == true)
		{
			printf("Vous ne pouvez boire de l'alcool avec une gueule de bois.");
		}
		else
		{
			if (energy >= energy_max)
			{
				printf("Vous n'avez pas besoin de boire pour le moment: vous n'êtes pas fatigué(e) et vous disposez de toute votre énergie.\n");
			}
			else
			{
				stat_number_alcohol++;
				printf("Vous avez la tête qui tourne, limite envie de vomir, mais au moins ça vous a réveillé.\n");
				energy = energy_max;
				bag[item] = 0;
				alcohol = true;
				sort_empty_racism(bag,bag_size);
			}
		}
	}

	else if (print_item(bag[item],2).compare("23") == 0) // weapons à recharge
	{
		int prob_b, prob_k, killnb, dump_item;
		int random_prob;
		
		if (bag[item] == 116) {prob_b = 30; prob_k = 95; killnb=3; dump_item=115;} // tronçonneuse
		if (bag[item] == 149) {prob_b = 30; prob_k = 95; killnb=1; dump_item=88;} // revolver
		if (bag[item] == 148) {prob_b = 15; prob_k = 95; killnb=rand()%3+1; dump_item=87;} // fusil
		if (bag[item] == 155) {prob_b = 100; prob_k = 100; killnb=1; dump_item=154;} // lp pdg

		if (killnb>monsters) killnb = monsters;
		
		if (location.compare("Campement") == 0 || monsters <= 0)
		{
			printf("Vous n'avez pas besoin de faire cela pour le moment.");
		}
		else
		{
			random_prob = rand()%100;
			if (random_prob > prob_k)
			{
				if (killnb > monsters) killnb = monsters;
				monsters = monsters-killnb; // kill
				if (monsters < 0) monsters = 0;
				printf("Vous avez éliminé %d zombies en utilisant %s. Ha ! Ha ! Un peu plus de chair étalée... Ca soulage de supprimer du zombie de temps en temps.\n\n",killnb,print_item(22,0).c_str());
				stat_number_kills = stat_number_kills + killnb;
			}
			else
			{
				printf("Vous avez manqué votre coup !\n");
			}
			random_prob = rand()%100;
			if (random_prob < prob_b)
			{
				bag[item] = dump_item; // item déchargé
				printf("\n\nToutefois :  votre arme est déchargée.");
			}
		}
	}

	else if (print_item(bag[item],2).compare("24") == 0) // sport elec
	{
		if (injury == true)
		{
			printf("Vous ne pouvez utiliser cet objet en étant bléssé.");
		}
		else
		{
			if (energy >= energy_max)
			{
				printf("Vous n'avez pas besoin de boire pour le moment: vous n'êtes pas fatigué(e) et vous disposez de toute votre énergie.\n");
			}
			else
			{
				printf("Vous vous sentez renaître, vous vous sentez détendue. Par contre il y a comme une odeur de chair brulée...\n");
				injury = true;
				energy = 5;
				bag[item] = 142;
				sort_empty_racism(bag,bag_size);
				stat_success_maso++;
			}
		}
	}
	
	else if (print_item(bag[item],2).compare("25") == 0) // pmv
	{
		if (terror == false)
		{
			printf("Vous n'avez pas besoin de cela pour le moment.");
		}
		else
		{
			printf("Les effets de la terreur se dissipent...\n");
			terror = false;
			bag[item] = 144;
			sort_empty_racism(bag,bag_size);
			stat_success_maso++;
		}
	}
	
	else if (print_item(bag[item],2).compare("26") == 0) // ours
	{
		if (terror == false)
		{
			printf("Vous n'avez pas besoin de cela pour le moment.");
		}
		else
		{
			printf("Les effets de la terreur se dissipent...\n");
			terror = false;
			sort_empty_racism(bag,bag_size);
		}
	}
	
	else if (print_item(bag[item],2).compare("27") == 0) // reparation
	{
		i = 0;
		bool findBroke = false;
		
		for (i=0; i<bag_size; i++)
		{
			if (print_item(bag[i],2).compare("9") == 0)
			{
				findBroke = true;
				bag[i]--; // repare objet cassé dans le sac
			}
		}
		
		if (findBroke)
		{
			if (bag[item] == 151)
				bag[item] = 0;
			else if (bag[item] == 153)
				bag[item] = 152;
			sort_empty_racism(bag,bag_size);
			printf("Les objets cassés dans le sac ont été réparés");
		}
		else
			printf("Vous n'avez pas d'objets cassé dans votre sac.");
	}

	sort_empty_racism(bag,bag_size); // securité
	printf("\n\n");
	deep_mode = false;
	wait_user();
}


void Die4laugh::move_item(int number)
{
	int i, temp;
	bool count_bag = false;
	bool you_got_an_extension = false;
	bool you_got_heavy_item = false;
	bool y_a_pas = false;
	
	/* translation du number de base ground à ground_first/ground_index */
	if (number > bag_size) // ground to bag
	{
		/*i=0; printf("\nTAB GROUND :"); while (ground[i] != 0)
		{
			printf("%d;",ground[i]);
			i++;
		}i=0;
		printf("\nTAB GROUND_FIRST :"); while (ground_first[i] != 0)
		{
			printf("%d;",ground_first[i]);
			i++;
		}*/
		i=0;
		temp = number;
		/* crée une limite pour ne pas dépasser au dela de ground_first */
		while (ground[i] != 0)
		{
			//printf("\ni = %d, ground_first[i] = %d, ground[i] = %d",i,ground_first[number-bag_size-1],ground[i]);
			if (ground[i] == ground_first[number-bag_size-1])
			{
				temp = i+bag_size+1;
				y_a_pas = false;
				break;
			}
			else
				y_a_pas = true;
			i++;
		}
		number = temp;
	}
	
	for (i=0; i<bag_size; i++) if (print_item(bag[i],2).compare("14") != 0 && bag[i] != 0) count_bag = true; // detecte si il y a des items autre que des extensions
	
	if (number > bag_size && !y_a_pas) // ground to bag
	{
		//printf("1: je detecte qu'il s'agit d'un ground to bag\n");
		if (print_item(ground[number-bag_size-1],2).compare("14") == 0) // si l'objet a rajouter est un slot
		{
			//printf("2: je detecte que l'objet du sol est une extension\n");
			for (i=0; i<bag_size; i++)
			{
				//printf("3: je cherche a %d si j'ai une extension dans mon sac\n",i);
				if (print_item(bag[i],2).compare("14") == 0) // si on a deja un objet de slot
				{
					you_got_an_extension = true;
					//printf("4: J'AI TROUVER A %d\n",i);
				}
			}
		}
		if (print_item(ground[number-bag_size-1],4).compare("yes") == 0) // si l'objet a rajouter est encombrant
		{
			for (i=0; i<bag_size; i++)
			{
				if (print_item(bag[i],4).compare("yes") == 0) // si on a deja un objet encombrant
				{
					you_got_heavy_item = true;
				}
			}
		}
	}

	if (number >= 1 && number <= bag_size) // bag to ground
	{
		for (i=0; i<ground_size; i++)
		{
			if (ground[i] == 0)
			{
				if (print_item(bag[number-1],2).compare("14") == 0 && count_bag)
				{
					clean();
					printf("Vous devez d'abord vider l'intégralité de votre sac avant de pouvoir déposer une extension de sac.\n");
					wait_user();
					break;
				}
				else
				{
					ground[i] = bag[number-1]; // ajout de l'item au sol
					bag[number-1] = 0; // suppression du sac
					break;
				}
			}
		}
		sort_empty_racism(bag,bag_size); // tri du sac pour ne pas laisser d'espace vide
	}
	if (number > bag_size && !y_a_pas) // ground to bag
	{
		for (i=0; i<bag_size; i++)
		{
			//printf("bag : %d / !slot : %d / i : %d\n",bag[i],!you_got_an_extension,i);
			if (bag[i] == 0 && !you_got_an_extension) // trouve un emplacement vide si l'objet n'est pas une extension lorsqu'on en a deja une
			{
				if (you_got_heavy_item)
				{
					clean();
					printf("Vous portez déjà un objet encombrant.\n");
					wait_user();
					break;
				}
				else
				{
					bag[i] = ground[number-bag_size-1]; // ajout de l'item au sac
					ground[number-bag_size-1] = 0; // suppression de l'item au sol
					break;
				}
			}
		}
	}
	sort_empty_racism(bag,bag_size); // tri du sac pour ne pas laisser d'espace vide
	sort_empty_racism(ground,ground_size); // tri du sac pour ne pas laisser d'espace vide
}


void Die4laugh::add_item(int number)
{
	sort_empty_racism(bag,bag_size);
	int i;
	bool you_got_bagged = false;
	bool you_got_an_extension = false;
	bool you_got_heavy_item = false;  
	for (i=0; i<bag_size; i++)
		if (print_item(bag[i],2).compare("14") == 0) // si on a un objet de slot
			if (print_item(number,2).compare("14") == 0) // si l'objet a rajouter est un slot
				you_got_an_extension = true;
	for (i=0; i<bag_size; i++)
		if (print_item(bag[i],4).compare("yes") == 0) // si on a un objet encombrant
			if (print_item(number,4).compare("yes") == 0) // si l'objet a rajouter est encombrant
				you_got_heavy_item = true;
	
	// ajout au sac/sol
	for (i=0; i<bag_size; i++)
	{
		//printf("bag %d id %d\n",i,bag[i]);
		if (bag[i] == 0 && !you_got_an_extension && !you_got_heavy_item) // si le sac a un emplacement vide et pas d'extansion
		{
			bag[i] = number; // on met l'objet dedans
			printf("L'objet a été ajouté à votre sac.\n\n");
			you_got_bagged = true;
			break;
		}
	}
	if (!you_got_bagged)
	{
		for (i=0; i<=ground_size; i++) // on met l'objet au sol
		{
			if (ground[i] == 0)
			{
				ground[i] = number;
				if (you_got_heavy_item)
					printf("Cependant, vous portez déjà un objet encombrant : l'objet a été déposé au sol.\n\n");
				else
					printf("Cependant votre sac est plein : l'objet a été déposé au sol.\n\n");
				break;
			}
		}
	}
}


void Die4laugh::a_use_items()
{
	int i, choice;
	bool empty = true;
	
	deep_mode = true;
	
	while (deep_mode == true)
	{
		clean();
		
		for (i=0; i<bag_size; i++)
		{
			if (bag[i] != 0)
			{
				empty = false;
			}
		}
		if (empty)
		{
			printf(" Pas d'objets à utiliser !\n\n");
			deep_mode = false;
			wait_user();
		}
		else
		{
			for (i=0; i<bag_size; i++)
		 	{
				printf(" [%d] ",i+1);
				if (print_item(bag[i],2).compare("1") == 0) {printf("Boire	");}
				else if (print_item(bag[i],2).compare("2") == 0) {printf("Ouvrir	");}
				else if (print_item(bag[i],2).compare("3") == 0) {printf("Manger	");}
				else if (print_item(bag[i],2).compare("4") == 0) {printf("Assembler	");}
				else if (print_item(bag[i],2).compare("9") == 0) {printf("Attaquer	");}
				else if (print_item(bag[i],2).compare("8") == 0) {printf("Prendre	");}
				else if (print_item(bag[i],2).compare("11") == 0) {printf("Utiliser	");}
				else if (print_item(bag[i],2).compare("12") == 0) {printf("Prendre	");}
				else if (print_item(bag[i],2).compare("16") == 0) {printf("Utiliser	");}
				else if (print_item(bag[i],2).compare("17") == 0) {printf("Attaquer	");}
				else if (print_item(bag[i],2).compare("18") == 0) {printf("Prendre	");}
				else if (print_item(bag[i],2).compare("19") == 0) {printf("Prendre	");}
				else if (print_item(bag[i],2).compare("20") == 0) {printf("Prendre	");}
				else if (print_item(bag[i],2).compare("21") == 0) {printf("Utiliser	");}
				else if (print_item(bag[i],2).compare("22") == 0) {printf("Boire	");}
				else if (print_item(bag[i],2).compare("23") == 0) {printf("Attaquer	");}
				else if (print_item(bag[i],2).compare("24") == 0) {printf("Utiliser	");}
				else if (print_item(bag[i],2).compare("25") == 0) {printf("Utiliser	");}
				else if (print_item(bag[i],2).compare("26") == 0) {printf("Utiliser	");}
				else if (print_item(bag[i],2).compare("27") == 0) {printf("Utiliser	");}
				else {printf("	x	");}
				printf("	: %s\n",print_item(bag[i],0).c_str());
				printf("%s\n\n",print_item(bag[i],1).c_str());
			}
			printf("Que voulez vous faire ?\n");
			display_actions();
			wait_for_action();
			deep_mode = false;
		}
	}
}


void Die4laugh::a_dig_items()
{
	bool okay, you_got_bagged;
	int number, item_found, proba, i;
	
	okay = false;

	clean();
	
	if (terror == true) printf("Impossible de fouiller, vous êtes littéralement tétanisé(e) !\n"); else
	{
		number = rand()%5; // une chance sur 4 de rien trouvé
		
		if (number == 0)
		{
			printf("Après des recherches épuisantes, vous n'avez rien trouvé d'autre que la vacuité de ces moments perdus...\n\n");
		}
		else
		{
			if (location.compare("Désert (zone épuisé)") == 0)
			{
				item_found = rand()%5;
				if (item_found >= 2)
					item_found = 33;
				else
					item_found = 34;
			}
			else
			{
				while (!okay)
				{
					item_found = rand()%nb_items+1; // prend un objet au hasard
					
					std::stringstream ss;  
					ss << print_item(item_found,3);
					ss >> proba; // recupere sa probabilité en int (sur 100)
					
					number = rand()%100; // nb aleatoire entre 1 et 100
					//printf("objet : %s %s :",print_item(item_found,0).c_str(),print_item(item_found,3).c_str()); // détails
					if (proba >= number) // si la proba est plus élevé que le nb généré, l'item est trouvé, sinon on recherche une nouvelle fois
					{
						okay = true;
					}
				}
			}
			printf("Après de longues recherches, vous finissez par trouver %s par terre...\n\n",print_item(item_found,0).c_str());
			add_item(item_found);
			kilometers_exhausted[kilometers]++; // objet trouvé à ce kilomètre, épuisement possible
		}
		drained = true;
	}
	wait_user();
}


void Die4laugh::a_dig_location_items()
{
	int number, final_item;
	
	clean();
	
	number = rand()%5; // 1 chance sur 5 de rien trouvé
	if (number == 0)
	{
		printf("\n\nAprès des recherches épuisantes, vous n'avez rien trouvé d'autre que la vacuité de ces moments perdus...\n\n");
	}
	else
	{
		if (location.compare("Petite maison") == 0)
		{
			int possible_items[11] = {1,2,3,6,13,15,16,17,19,35,36};
			final_item = open(possible_items, 11);
		}
		if (location.compare("Puits abandonné") == 0)
		{
			int possible_items[11] = {3,3,3,3,3,3,25,25,25,25,29};
			final_item = open(possible_items, 11);
		}
		if (location.compare("Centrale hydrolique") == 0)
		{
			int possible_items[3] = {25,3,36};
			final_item = open(possible_items, 3);
		}
		if (location.compare("Camion en panne") == 0)
		{
			int possible_items[11] = {1,2,7,6,15,16,17,19,23,35,36};
			final_item = open(possible_items, 11);
		}
		if (location.compare("Petit bois obscur") == 0)
		{
			int possible_items[8] = {33,34,33,34,33,34,35,36};
			final_item = open(possible_items, 8);
		}
		if (location.compare("Carcasses de voitures") == 0)
		{
			int possible_items[9] = {50,64,33,36,46,36,50,25,151};
			final_item = open(possible_items, 9);
		}
		if (location.compare("Carrière effondrée") == 0)
		{
			int possible_items[13] = {53,53,53,53,53,61,61,35,36,42,43,36,35};
			final_item = open(possible_items, 13);
		}
		if (location.compare("Caveau familial") == 0)
		{
			int possible_items[8] = {87,87,87,88,75,75,75,36};
			final_item = open(possible_items, 8);
		}
		if (location.compare("Ancien Velib") == 0)
		{
			int possible_items[4] = {75,38,39,79};
			final_item = open(possible_items, 4);
		}
		if (location.compare("Carlingue d'avion") == 0)
		{
			int possible_items[15] = {54,46,46,46,50,50,50,89,89,89,42,36,42,71,52};
			final_item = open(possible_items, 15);
		}
		if (location.compare("Chantiers à l'abandon") == 0)
		{
			int possible_items[16] = {42,42,42,50,50,53,53,27,27,64,66,80,89,35,36,152};
			final_item = open(possible_items, 16);
		}
		if (location.compare("Meubles KIELA") == 0)
		{
			int possible_items[9] = {73,73,61,90,65,67,21,71,35};
			final_item = open(possible_items, 9);
		}
		if (location.compare("Route barrée") == 0)
		{
			int possible_items[9] = {62,62,62,50,50,35,35,36,36};
			final_item = open(possible_items, 9);
		}
		if (location.compare("Ambulance") == 0)
		{
			int possible_items[9] = {16,16,91,91,91,91,91,37,41};
			final_item = open(possible_items, 9);
		}
		if (location.compare("Villa délabrée") == 0)
		{
			int possible_items[9] = {15,123,122,65,2,71,17,16,141};
			final_item = open(possible_items, 9);
		}
		if (location.compare("Supermarché pillé") == 0)
		{
			int possible_items[18] = {83,102,89,95,121,3,98,99,25,153,15,90,35,36,111,112,117,114};
			final_item = open(possible_items, 18);
		}
		if (location.compare("Bar miteux") == 0)
		{
			int possible_items[9] = {98,98,98,99,99,20,139,1,96};
			final_item = open(possible_items, 9);
		}
		if (location.compare("BricoTout") == 0)
		{
			int possible_items[9] = {151,152,153,91,27,112,114,51,117};
			final_item = open(possible_items, 9);
		}
		if (location.compare("Armurerie'N'Massy") == 0)
		{
			int possible_items[9] = {148,149,96,87,88,31,108,48,88};
			final_item = open(possible_items, 9);
		}
		if (location.compare("Stand de fête foraine") == 0)
		{
			int possible_items[3] = {136,134,144};
			final_item = open(possible_items, 3);
		}
		
		printf("\n\nLa peur vous prend aux tripes tandis que vous explorez %s...\nNéanmoins, ça n'aura pas été inutile puisque vous finissez par trouver %s.\n\n",location.c_str(),print_item(final_item,0).c_str());
		add_item(final_item);
	}
	drained_location = true;
	wait_user();

}


void Die4laugh::a_back_to_home()
{
	int i;
	
	clean();
	
	for (i=0; i<ground_size; i++)
	{
		//if (i<5 || i > 995) printf("SAVE %d = %d --- ground[%d] = kilometers_save[%d][%d]\n",kilometers_save[kilometers][i],ground[i],kilometers,i,i);
		kilometers_save[kilometers][i] = ground[i];
	}
	
	if (energy < energy_to_brb)
	{
		printf("Vous êtes trop fatigué(e)...\n");
		wait_user();
	}
	else
	{
		energy = energy - energy_to_brb;
		kilometers = 0;
		location = "Campement";
		for (i=0; i<ground_size; i++)
		{
			ground[i] = ground_home[i];
		}
	}
}


void Die4laugh::a_next_kilometer()
{
	int i;
	
	clean();

	if (energy <= 0)
	{
		printf("Vous êtes trop fatigué(e) pour aller plus loin !\n\n");
		wait_user();
	}
	else if (stuck == true)
	{
		printf("Vous êtes submergés par les zombies, tentez d'en tuer, de fuir ou de vous échapper...");
	}
	else
	{
		if (location.compare("Campement") == 0)
		{
			for (i=0; i<=ground_size; i++)
			{
				ground_home[i] = ground[i]; // sauvegarde des objets au sol
			}
		}
		else
		{
			//sauvegarde des objets au sol
			for (i=0; i<ground_size; i++)
			{
				//if (i<5 || i > 995) printf("SAVE %d = %d --- ground[%d] = kilometers_save[%d][%d]\n",kilometers_save[kilometers][i],ground[i],kilometers,i,i);
				kilometers_save[kilometers][i] = ground[i];
			}
		}
		
		// zonzon
		if (location.compare("Campement") == 0)
		{
			monsters = 0;
		}
		
		kilometers = kilometers + 1;
		reload_location();
		stat_number_killometers++;
		energy = energy - 1;
		reset_ground();
		drained = false;
		drained_location = false;
		
		//upload des objets au sol
		for (i=0; i<ground_size; i++)
		{
			//if (i<5 || i > 995) printf("UPLOAD %d = %d --- ground[%d] = kilometers_save[%d][%d]\n",ground[i],kilometers_save[kilometers][i],i,kilometers,i);
			ground[i] = kilometers_save[kilometers][i];
		}
		
		stuck_f();
		
		if (kilometers >= 1) {energy_to_brb = 1;}
		if (kilometers >= 3) {energy_to_brb = 2;}
		if (kilometers >= 9) {energy_to_brb = 3;}
		if (kilometers >= 27) {energy_to_brb = 4;}
		if (kilometers >= 81) {energy_to_brb = 5;}
		if (kilometers >= 243) {energy_to_brb = 6;}
		
		if (kilometers > stat_max_killometers)
			stat_max_killometers = kilometers;
	}
}


void Die4laugh::a_sleep_home()
{
	new_day();
}


void Die4laugh::a_sleep_outside()
{
	camping = true;
	new_day();
	camping = false;
}


int Die4laugh::count_camp_item(int id) // (searsch)
{
	int i, counter;
	counter = 0;
	for (i=0; i<bag_size; i++)
	{
		if (bag[i] == id)
		{
			counter++; // return number of item found
		}
	}
	for (i=0; i<ground_size; i++)
	{
		if (ground[i] == id)
		{
			counter++; // return number of item found
		}
	}
	return counter;
}


void Die4laugh::remove_camp_item(int id, int remove_nb)  // (searsch,number to remove) 
{
	/* count_camp_item(int id) a utiliser avant pour check la precense des items !!!! */
	int i, counter;
	counter = remove_nb;
	
	//i=0; while (ground[i] != 0) {printf("Avant : ground[%d] = %d\n",i,ground[i]); i++;}
	
	i = 0;
	while (i<bag_size && counter > 0)
	{
		if (bag[i] == id)
		{
			bag[i] = 0;
			sort_empty_racism(bag,bag_size);
		}
		i++;
	}
	
	i = 0;
	while (i<ground_size && counter > 0)
	{
		if (ground[i] == id)
		{
			//printf("trouvé à ground[%d] = %d == id = %d\n",i,ground[i],id);
			ground[i] = 0;
			counter --;
		}
		i++;
	}
	//i=0; while (i<20) {printf("avant l'après : ground[%d] = %d\n",i,ground[i]); i++;}
	for (i=0; i<remove_nb; i++)
	{
		sort_empty_racism(ground,ground_size);
		sort_empty_racism(bag,bag_size);
	}
	
	//i=0; while (i<20) {printf("Après : ground[%d] = %d\n",i,ground[i]); i++;}
}


void Die4laugh::add_camp_item(int id, int add_nb)  // (searsch,number to add) place au sol
{
	int i, counter;
	counter = add_nb;
	
	i = 0;
	while (i<ground_size && counter > 0)
	{
		if (ground[i] == 0)
		{
			ground[i] = id;
			counter--;
		}
		i++;
	}
}


void Die4laugh::a_builds_camp()
{
	int int_choice;
	
	clean();
	
	if (ch_waterwell == false) printf("[1] Puits (%d énergies) : %d/1 Souche de bois pourrie + %d/1 Débris métalliques\n",ch_waterwell_nj,count_camp_item(34),count_camp_item(33)); else printf("[-] (Puits)\n");
	printf(" -> Permet de récupérer une ration d'eau par jour\n\n");
	
	if (ch_workshop == false) printf("[2] Atelier (%d énergies) : %d/3 Planches tordues + %d/2 Ferraille\n",ch_workshop_nj,count_camp_item(35),count_camp_item(36)); else printf("[-] (Atelier)\n");
	printf(" -> Permet de transformer et démonter des objets\n\n");
	
	if (ch_foundation == false) printf("[3] Fondations (%d énergies) : %d/2 Poutre rafistolée + %d/2 Structure métallique\n",ch_foundation_nj,count_camp_item(43),count_camp_item(42)); else printf("[-] (Fondations)\n");
	printf(" -> Pour réaliser d'autres chantiers\n\n");
	
	if (ch_workshop == true) if (ch_shed == false) printf("[4] Appentis (%d énergies) : %d/3 Poutre rafistolée + %d/2 Tube de cuivre + %d/2 Poignée de vis et écrous + %d/1 Table Järpen\n",ch_shed_nj,count_camp_item(43),count_camp_item(52),count_camp_item(50),count_camp_item(65)); else printf("[-] (Appentis)\n");
	if (ch_workshop == true) printf(" -> Réduire le temps de travail à l'atelier\n\n");
	
	if (ch_shed == true) if (ch_factory == false) printf("[5] Manufacture (%d énergies) : %d/1 Scie à métaux + %d/2 Poutre rafistolée + %d/2 Structure métallique\n",ch_factory_nj,count_camp_item(118),count_camp_item(43),count_camp_item(42)); else printf("[-] (Manufacture)\n");
	if (ch_shed == true) printf(" -> Réduire le temps de travail à l'atelier\n\n");
	
	if (ch_foundation == true) if (ch_watchtower == false) printf("[6] Mirador (%d énergies) : %d/1 Téléscope + %d/1 Table Järpen + %d/1 Composant électronique + %d/3 Poutre rafistolée + %d/1 Structure métallique\n",ch_watchtower_nj,count_camp_item(119),count_camp_item(65),count_camp_item(45),count_camp_item(43),count_camp_item(42)); else printf("[-] (Mirador)\n");
	if (ch_foundation == true) printf(" -> Régènere certaines zones du désert\n\n");
	
	if (ch_foundation == true) if (ch_cuisine == 0) printf("[7] Cuisine 1 (%d énergies) : %d/1 Canif dérisoire + %d/1 Planche tordue\n",ch_cuisine_nj,count_camp_item(23),count_camp_item(35));
		else if (ch_cuisine == 1) printf("[7] Cuisine 2 (%d énergies) : %d/1 Four cancérigène + %d/1 Ferraille\n",ch_cuisine_nj,count_camp_item(126),count_camp_item(36));
		else if (ch_cuisine == 2) printf("[7] Cuisine 3 (%d énergies) : %d/1 Réfrigérateur d'étudiant + %d/1 Poignée de vis et écrous\n",ch_cuisine_nj,count_camp_item(128),count_camp_item(50));
		else printf("[-] (Cuisine 3)\n");
	if (ch_foundation == true) printf(" -> Coin aménagé de manière très sommaire pour y préparer des rations de meilleure qualité\n\n");
	
	if (ch_home == 0) printf("[8] Campement - tente (%d énergies)\n",ch_home_nj);
		else if (ch_home == 1) printf("[8] Campement - taudis (%d énergies) : %d/1 Planche tordue\n",ch_home_nj,count_camp_item(35));
		else if (ch_home == 2) printf("[8] Campement - baraque (%d énergies) : %d/1 Planche tordue + %d/1 Ferraille\n",ch_home_nj,count_camp_item(35),count_camp_item(36));
		else if (ch_home == 3) printf("[8] Campement - maison (%d énergies) : %d/1 Poutre rafistolée + %d/1 Structure métallique\n",ch_home_nj,count_camp_item(43),count_camp_item(42));
		else if (ch_home == 4) printf("[8] Campement - maison cloturée (%d énergies) : %d/1 Grosse chaîne rouillée + %d/1 Structure métallique\n",ch_home_nj,count_camp_item(29),count_camp_item(42));
		else if (ch_home == 5) printf("[8] Campement - abri fortifié (%d énergies) : %d/1 Planche tordue + %d/2 Ferraille + %d/1 Pavés de bétons informes\n",ch_home_nj,count_camp_item(35),count_camp_item(36),count_camp_item(62));
		else if (ch_home == 6) printf("[8] Campement - bunker (%d énergies) : %d/1 Fragment de tôle + %d/3 Ferraille + %d/2 Pavés de bétons informes + %d/2 Poignée de vis et écrous\n",ch_home_nj,count_camp_item(49),count_camp_item(36),count_camp_item(62),count_camp_item(50));
		else if (ch_home == 7) printf("[8] Campement - château (%d énergies) : %d/3 Fragment de tôle + %d/5 Ferraille + %d/5 Planche tordue + %d/3 Pavés de bétons informes + %d/3 Poignée de vis et écrous\n",ch_home_nj,count_camp_item(49),count_camp_item(36),count_camp_item(35),count_camp_item(62),count_camp_item(50));
		else printf("[-] Campement - château");
	if (ch_home == 0) printf(" -> Ajoute : 5 défenses\n\n");
		else if (ch_home == 1) printf(" -> Ajoute : 10 défenses\n\n");
		else if (ch_home == 2) printf(" -> Ajoute : 20 défenses\n\n");
		else if (ch_home == 3) printf(" -> Ajoute : 40 défenses\n\n");
		else if (ch_home == 7) printf(" -> Ajoute : 100 défenses\n\n");
		else if (ch_home == 8) printf(" -> \n\n");
		else printf(" -> Un campement imposant...\n\n");
	
	if (ch_home > 0) printf("[9] Renforts %d (%d énergies) : %d/1 Morceau de grillage\n",ch_barricade+1,ch_barricade_nj,count_camp_item(150));
	if (ch_home > 0) printf(" -> Ajoute : 5 défenses\n\n");
	
	if (ch_foundation == true) if (ch_fireworks == false) printf("[10] Feux d'artifices (%d énergies) : %d/2 Caisse de feux d'artifice + %d/1 Tube de lancement Floush + %d/1 Poudre Super-Fuzz\n",ch_fireworks_nj,count_camp_item(134),count_camp_item(56),count_camp_item(55)); else printf("[-] (Feux d'artifices)\n");
	if (ch_foundation == true) printf(" -> Ajoute : 200 défenses\n\n");
	
	if (ch_foundation == true) if (ch_vegetable == false) printf("[11] Potager (%d énergies) : %d/2 Poutre rafistolée + %d/7 Ration d'eau + %d/1 Produits pharmaceutiques\n",ch_vegetable_nj,count_camp_item(43),count_camp_item(3),count_camp_item(16)); else printf("[-] (Potager)\n");
	if (ch_foundation == true) printf(" -> Permet de créer des légumes pas trop moisis, des fruits qui commencent à pourrir avant de mûrir.\n\n");
	
	printf("[X] Quitter\n\n");
	
	printf("\nQue voulez vous faire ?\n> ");
	fflush(stdin);
	scanf("%d",&int_choice);
	
	clean();
	
	if (int_choice == 1 && ch_waterwell == false) //puits
	{
		if (count_camp_item(33) >= 1 && count_camp_item(34) >= 1)
		{
			// printf("nj : %d need : %d",energy,ch_waterwell_nj);
			if (energy >= ch_waterwell_nj)
			{
				printf("Vous avez utilisez %d énergies : le puits a été construit !\n",ch_waterwell_nj);
				energy = energy - ch_waterwell_nj;
				ch_waterwell_nj = 0;
				remove_camp_item(33,1); remove_camp_item(34,1);
				ch_waterwell = true;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_waterwell_nj = ch_waterwell_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 2 && ch_workshop == false) //atelier
	{
		if (count_camp_item(35) >= 3 && count_camp_item(36) >= 2)
		{
			if (energy >= ch_workshop_nj)
			{
				printf("Vous avez utilisez %d énergies : l'atelier a été construit !\n",ch_workshop_nj);
				energy = energy - ch_workshop_nj;
				ch_workshop_nj = 0;
				remove_camp_item(35,3); remove_camp_item(36,2);
				ch_workshop = true;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_workshop_nj = ch_workshop_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 3 && ch_foundation == false) //fondations
	{
		if (count_camp_item(43) >= 2 && count_camp_item(42) >= 2)
		{
			if (energy >= ch_foundation_nj)
			{
				printf("Vous avez utilisez %d énergies : les fondations ont étés construites !\n",ch_foundation_nj);
				energy = energy - ch_foundation_nj;
				ch_foundation_nj = 0;
				remove_camp_item(43,2); remove_camp_item(42,2);
				ch_foundation = true;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_foundation_nj = ch_foundation_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}

	else if (int_choice == 4 && ch_shed == false && ch_workshop == true) //appentis
	{
		if (count_camp_item(43) >= 4 && count_camp_item(52) >= 2 && count_camp_item(50) >= 2 && count_camp_item(65) >= 1)
		{
			if (energy >= ch_shed_nj)
			{
				printf("Vous avez utilisez %d énergies : l'appentis a été construit !\n",ch_shed_nj);
				energy = energy - ch_shed_nj;
				ch_shed_nj = 0;
				remove_camp_item(43,3); remove_camp_item(52,2); remove_camp_item(50,2); remove_camp_item(65,1);
				ch_shed = true;
				ch_workshop_nj--; // baisse une énergie à la construction
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_shed_nj = ch_shed_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}

	else if (int_choice == 5 && ch_factory == false && ch_shed == true) //manufacture
	{
		if (count_camp_item(118) >= 1 && count_camp_item(43) >= 2 && count_camp_item(42) >= 2)
		{
			if (energy >= ch_factory_nj)
			{
				printf("Vous avez utilisez %d énergies : la manufacture a été construite !\n",ch_factory_nj);
				energy = energy - ch_factory_nj;
				ch_factory_nj = 0;
				remove_camp_item(118,1); remove_camp_item(43,2); remove_camp_item(42,2);
				ch_factory = true;
				ch_workshop_nj--; // baisse une énergie à la construction
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_factory_nj = ch_factory_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 6 && ch_watchtower == false && ch_foundation == true) //mirador
	{
		if (count_camp_item(119) >= 1 && count_camp_item(65) >= 1 && count_camp_item(45) >= 1 && count_camp_item(43) >= 3 && count_camp_item(42) >= 1)
		{
			if (energy >= ch_watchtower_nj)
			{
				printf("Vous avez utilisez %d énergies : le mirador a été construit !\n",ch_watchtower_nj);
				energy = energy - ch_watchtower_nj;
				ch_watchtower_nj = 0;
				remove_camp_item(119,1); remove_camp_item(65,1); remove_camp_item(45,1); remove_camp_item(43,3); remove_camp_item(42,1);
				ch_watchtower = true;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_watchtower_nj = ch_watchtower_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 7 && ch_cuisine == 0 && ch_foundation == true) //cuisine 1
	{
		if (count_camp_item(23) >= 1 && count_camp_item(35) >= 1)
		{
			if (energy >= ch_cuisine_nj)
			{
				printf("Vous avez utilisez %d énergies : la cuisine a été construite !\n",ch_cuisine_nj);
				energy = energy - ch_cuisine_nj;
				ch_cuisine_nj = 3;
				remove_camp_item(23,1); remove_camp_item(35,1);
				ch_cuisine = 1;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_cuisine_nj = ch_cuisine_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 7 && ch_cuisine == 1 && ch_foundation == true) //cuisine 2
	{
		if (count_camp_item(126) >= 1 && count_camp_item(36) >= 1)
		{
			if (energy >= ch_cuisine_nj)
			{
				printf("Vous avez utilisez %d énergies : la cuisine lvl.2 a été construite !\n",ch_cuisine_nj);
				energy = energy - ch_cuisine_nj;
				ch_cuisine_nj = 3;
				remove_camp_item(126,1); remove_camp_item(36,1);
				ch_cuisine = 2;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_cuisine_nj = ch_cuisine_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 7 && ch_cuisine == 2 && ch_foundation == true) //cuisine 3
	{
		if (count_camp_item(128) >= 1 && count_camp_item(50) >= 1)
		{
			if (energy >= ch_cuisine_nj)
			{
				printf("Vous avez utilisez %d énergies : la cuisine lvl.3 a été construite !\n",ch_cuisine_nj);
				energy = energy - ch_cuisine_nj;
				ch_cuisine_nj = 0;
				remove_camp_item(128,1); remove_camp_item(50,1);
				ch_cuisine = 3;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_cuisine_nj = ch_cuisine_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 8 && ch_home == 0) //home 1
	{
		if (energy >= ch_home_nj)
		{
			printf("Vous avez utilisez %d énergies : la tente a étée construite !\n",ch_home_nj);
			energy = energy - ch_home_nj;
			ch_home_nj = 6;
			ch_home = 1;
			camp_def = camp_def + 5;
		}
		else
		{
			printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
			ch_home_nj = ch_home_nj - energy;
			energy = 0;
		}
		wait_user();
	}
	
	else if (int_choice == 8 && ch_home == 1) //home 2
	{
		if (count_camp_item(35) >= 1)
		{
			if (energy >= ch_home_nj)
			{
				printf("Vous avez utilisez %d énergies : le taudis a été construit !\n",ch_home_nj);
				energy = energy - ch_home_nj;
				ch_home_nj = 4;
				remove_camp_item(35,1);
				ch_home = 2;
				camp_def = camp_def + 10;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_home_nj = ch_home_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 8 && ch_home == 2) //home 3
	{
		if (count_camp_item(35) >= 1 && count_camp_item(36) >= 1)
		{
			if (energy >= ch_home_nj)
			{
				printf("Vous avez utilisez %d énergies : la baraque a étée construite !\n",ch_home_nj);
				energy = energy - ch_home_nj;
				ch_home_nj = 6;
				remove_camp_item(35,1); remove_camp_item(36,1);
				ch_home = 3;
				camp_def = camp_def + 20;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_home_nj = ch_home_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 8 && ch_home == 3) //home 4
	{
		if (count_camp_item(43) >= 1 && count_camp_item(42) >= 1)
		{
			if (energy >= ch_home_nj)
			{
				printf("Vous avez utilisez %d énergies : la maison a étée construite !\n",ch_home_nj);
				energy = energy - ch_home_nj;
				ch_home_nj = 6;
				remove_camp_item(43,1); remove_camp_item(42,1);
				ch_home = 4;
				camp_def = camp_def + 40;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_home_nj = ch_home_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 8 && ch_home == 4) //home 5
	{
		if (count_camp_item(29) >= 1 && count_camp_item(42) >= 1)
		{
			if (energy >= ch_home_nj)
			{
				printf("Vous avez utilisez %d énergies : la maison cloturée a étée construite !\n",ch_home_nj);
				energy = energy - ch_home_nj;
				ch_home_nj = 7;
				remove_camp_item(29,1); remove_camp_item(42,1);
				ch_home = 5;
				camp_def = camp_def + 50;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_home_nj = ch_home_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 8 && ch_home == 5) //home 6
	{
		if (count_camp_item(29) >= 1 && count_camp_item(62) >= 1 && count_camp_item(42) >= 2)
		{
			if (energy >= ch_home_nj)
			{
				printf("Vous avez utilisez %d énergies : l'abri fortifiée a été construite !\n",ch_home_nj);
				energy = energy - ch_home_nj;
				ch_home_nj = 8;
				remove_camp_item(29,1); remove_camp_item(42,2); remove_camp_item(62,1);
				ch_home = 6;
				camp_def = camp_def + 50;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_home_nj = ch_home_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 8 && ch_home == 6) //home 7
	{
		if (count_camp_item(49) >= 1 && count_camp_item(36) >= 3 && count_camp_item(62) >= 2 && count_camp_item(50) >= 2)
		{
			if (energy >= ch_home_nj)
			{
				printf("Vous avez utilisez %d énergies : le bunker a été construite !\n",ch_home_nj);
				energy = energy - ch_home_nj;
				ch_home_nj = 12;
				remove_camp_item(49,1); remove_camp_item(42,3); remove_camp_item(62,2); remove_camp_item(50,2);
				ch_home = 7;
				camp_def = camp_def + 50;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_home_nj = ch_home_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 8 && ch_home == 7) //home 8
	{
		if (count_camp_item(49) >= 3 && count_camp_item(35) >= 5 && count_camp_item(36) >= 5 && count_camp_item(50) >= 3 && count_camp_item(62) >= 3)
		{
			if (energy >= ch_home_nj)
			{
				printf("Vous avez utilisez %d énergies : le château a été construite !\n",ch_home_nj);
				energy = energy - ch_home_nj;
				ch_home_nj = 0;
				remove_camp_item(49,3); remove_camp_item(62,3); remove_camp_item(35,5); remove_camp_item(36,5); remove_camp_item(50,3);
				ch_home = 8;
				camp_def = camp_def + 100;
				stat_success_castle++;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_home_nj = ch_home_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	}
	
	else if (int_choice == 9 && ch_home > 0) //barricade
	{
		if (energy >= ch_barricade_nj)
		{
			printf("Vous avez utilisez %d énergies : Barricades %d a été construit !\n",ch_barricade_nj,ch_barricade);
			energy = energy - ch_barricade_nj;
			ch_barricade_nj = 3;
			ch_barricade++;
			camp_def = camp_def + 5;
		}
		else
		{
			printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
			ch_barricade_nj = ch_barricade_nj - energy;
			energy = 0;
		}
		wait_user();
	}
	
	else if (int_choice == 10 && ch_fireworks == false && ch_foundation == true) //feux d'artifices
	{
		if (count_camp_item(134) >= 2 && count_camp_item(56) >= 1 && count_camp_item(55) >= 1)
		{
			if (energy >= ch_fireworks_nj)
			{
				printf("Vous avez utilisez %d énergies : le feux d'artifices a été construit !\n",ch_fireworks_nj);
				energy = energy - ch_fireworks_nj;
				ch_fireworks_nj = 0;
				remove_camp_item(134,2); remove_camp_item(56,1); remove_camp_item(55,1);
				ch_fireworks = true;
				camp_def = camp_def + 200;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_fireworks_nj = ch_watchtower_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	} 
	
	else if (int_choice == 11 && ch_vegetable == false && ch_foundation == true) //potager
	{
		if (count_camp_item(43) >= 2 && count_camp_item(3) >= 7 && count_camp_item(16) >= 1)
		{
			if (energy >= ch_vegetable_nj)
			{
				printf("Vous avez utilisez %d énergies : le potager a été construit !\n",ch_vegetable_nj);
				energy = energy - ch_vegetable_nj;
				ch_vegetable_nj = 0;
				remove_camp_item(43,2); remove_camp_item(3,7); remove_camp_item(16,1);
				ch_vegetable = true;
			}
			else
			{
				printf("Vous avez utilisez %d énergies sur ce chantier.\n",energy);
				ch_fireworks_nj = ch_vegetable_nj - energy;
				energy = 0;
			}
		}
		else {printf("Vous n'avez pas les matériaux nécessaires !\n");}
		wait_user();
	} 
	
	sort_empty_racism(ground,ground_size); sort_empty_racism(bag,bag_size); sort_empty_racism(bag,bag_size);
	fflush(stdin);
}


void Die4laugh::a_ch_waterwell()
{
	clean();
	
	printf("Vous avez pris votre ration d'eau quotidienne\n");
	add_item(3);
	waterwell_today = true;
	
	wait_user();
}


void Die4laugh::a_ch_workshop()
{
	int int_choice;
	int found;
	
	clean();
	
	printf(" ATELIER :\n%d coût en énergie\n%d énergies disponible\n------------------------------------\n\n",workshop_energy,energy);
	
	int metal_scrap = count_camp_item(34);
	int wood_stump = count_camp_item(33);
	int nice_wood_stump = count_camp_item(44);
	int planks = count_camp_item(35);
	int metal = count_camp_item(36);
	int beam = count_camp_item(43);
	int metallic_struct = count_camp_item(42);
	int fragment_metal = count_camp_item(49);
	int sheet_metal = count_camp_item(64);
	int big_chest = count_camp_item(114);
	int mechanism = count_camp_item(120);
	int mek = count_camp_item(73);
	int aep = count_camp_item(89);
	int crate = count_camp_item(112);
	int metal_crate = count_camp_item(113);
	int repair_crate_broke = count_camp_item(152);
	int repair_crate = count_camp_item(153);

	if (metal_scrap > 0)
		printf("[1] Transformer :	(x%d) Débris métalliques			->	(x%d) Ferraille\n",metal_scrap,metal);
	if (wood_stump > 0)
		printf("[2] Transformer :	(x%d) Souche de bois pourrie		->	(x%d) Planche tordue\n",wood_stump,planks);
	if (nice_wood_stump > 0)
		printf("[3] Transformer :	(x%d) Souche en bon état			->	(x%d) Planche tordue\n",nice_wood_stump,planks);
	if (planks > 0)
		printf("[4] Transformer :	(x%d) Planche tordue				->	(x%d) Poutre rafistolée\n",planks,beam);
	if (metal > 0)
		printf("[5] Transformer :	(x%d) Ferraille						->	(x%d) Structure métallique\n",metal,metallic_struct);
	if (beam > 0)
		printf("[6] Transformer :	(x%d) Poutre rafistolée				->	(x%d) Planche tordue\n",beam,planks);
	if (metallic_struct > 0)
		printf("[7] Transformer :	(x%d) Structure métallique			->	(x%d) Ferraille\n",metallic_struct,metal);
	if (fragment_metal > 0)
		printf("[8] Transformer :	(x%d) Fragments de tôle				->	(x%d) Plaque de tôle\n",fragment_metal,sheet_metal);
	if (big_chest > 0)
		printf("[9] Ouvrir :		(x%d) Gros coffre en métal		->	???\n",big_chest);
	if (mechanism > 0)
		printf("[10] Démonter :		(x%d) Mécanisme				->	???\n",mechanism);
	if (mek > 0)
		printf("[11] Démonter :		(x%d) Meuble en kit 			->	???\n",mek);
	if (aep > 0)
		printf("[12] Démonter :		(x%d) Appareil électronique en panne	->	???\n",aep);
	if (crate > 0)
		printf("[13] Ouvrir :		(x%d) Caisse de matériel			->	???\n",crate);
	if (metal_crate > 0)
		printf("[14] Ouvrir :		(x%d) Boîte en métal			->	???\n",metal_crate);
	if (repair_crate_broke > 0)
		printf("[15] Réparer :		(x%d) Kit de bricolage abimé		->	(x%d) Kit de bricolage\n",repair_crate_broke,repair_crate);
	printf("\n[X] Quitter\n\n");
	
	printf("\nQue voulez vous faire ?\n> ");
	fflush(stdin);
	scanf("%d",&int_choice);
	
	clean();
	
	if (int_choice > 0 && int_choice < 15)
	{
		if (energy < workshop_energy)
		{
			printf("Il vous faut %d énergies pour travailler à l'atelier.\n",workshop_energy);
		}
		else if (int_choice == 1 && metal_scrap > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(34, 1);
			add_camp_item(36, 1);
			printf("Vous avez fabriqué Ferraille à partir de Débris métalliques.\n");
		}
		else if (int_choice == 2 && wood_stump > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(33, 1);
			add_camp_item(35, 1);
			printf("Vous avez fabriqué Planche tordue à partir de Souche de bois pourrie.\n");
		}
		else if (int_choice == 3 && nice_wood_stump > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(44, 1);
			add_camp_item(35, 1);
			printf("Vous avez fabriqué Planche tordue à partir de Souche en bon état.\n");
		}
		else if (int_choice == 4 && planks > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(35, 1);
			add_camp_item(43, 1);
			printf("Vous avez fabriqué Poutre rafistolée à partir de Planche tordue.\n");
		}
		else if (int_choice == 5 && metal > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(36, 1);
			add_camp_item(42, 1);
			printf("Vous avez fabriqué Structure métallique à partir de Ferraille.\n");
		}
		else if (int_choice == 6 && beam > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(43, 1);
			add_camp_item(36, 1);
			printf("Vous avez fabriqué Planche tordue à partir de Poutre rafistolée.\n");
		}
		else if (int_choice == 7 && metallic_struct > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(42, 1);
			add_camp_item(36, 1);
			printf("Vous avez fabriqué Ferraille à partir de Structure métallique.\n");
		}
		else if (int_choice == 8 && fragment_metal > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(49, 1);
			add_camp_item(64, 1);
			printf("Vous avez fabriqué Plaque de tole à partir de Fragment de tole.\n");
		}
		else if (int_choice == 9 && big_chest > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(114, 1);
			add_camp_item(108, 1);
			printf("Vous avez trouvé Tronçonneuse incomplète à partir de Gros coffre en métal.\n");
		}
		else if (int_choice == 10 && mechanism > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(120, 1);
			int possible_items[4] = {50,52,33,36};
			found = open(possible_items,4);
			add_camp_item(found, 1);
			printf("Vous avez démonté %s à partir de Méchanisme.\n",print_item(found,0).c_str());
		}
		else if (int_choice == 11 && mek > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(73, 1);
			int possible_items[4] = {65,66,67};
			found = open(possible_items,3);
			add_camp_item(found, 1);
			printf("Vous avez démonté %s à partir de Meuble en kit.\n",print_item(found,0).c_str());
		}
		else if (int_choice == 12 && aep > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(89, 1);
			int possible_items[4] = {15,45,48,50};
			found = open(possible_items,4);
			add_camp_item(found, 1);
			printf("Vous avez démonté %s à partir de Appareil éléctronique en panne.\n",print_item(found,0).c_str());
		}
		else if (int_choice == 13 && crate > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(112, 1);
			int possible_items[6] = {47,15,50,16,51,52};
			found = open(possible_items,6);
			add_camp_item(found, 1);
			printf("Vous avez trouvé %s à partir de Caisse de matériel.\n",print_item(found,0).c_str());
		}
		else if (int_choice == 14 && metal_crate > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(113, 1);
			int possible_items[6] = {95,19,98,99,20,15};
			found = open(possible_items, 6);
			add_camp_item(found, 1);
			printf("Vous avez trouvé %s à partir de Boîte en métal.\n",print_item(found,0).c_str());
		}
		else if (int_choice == 15 && repair_crate_broke > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(152, 1);
			add_camp_item(153, 1);
			printf("Vous avez fabriqué %s à partir de Kit de bricolage abimé.\n",print_item(153,0).c_str());
		}
		wait_user();
	}
	
	
}


void Die4laugh::a_runaway()
{	
	clean();
	
	if (terror == true) printf("Impossible de fuir, vous êtes littéralement tétanisé(e) !\n"); else
	{
		if (injury == true)
		{
			printf("Vous ne pouvez plus fuir lorsque vous êtes bléssé(e).");
		}
		else
		{
			if (rand()%4 == 0)
			{
				death(4);
			}
			else if (rand()%4 == 0)
			{
				stuck = false;
				a_next_kilometer();
				printf("Miracle, vous avez réussi à slalomer entre les obstacles et un bipode sans aucune égratinure !\nVous quittez la zone.\n");
			}
			else
			{
				stuck = false;
				injury = true;
				a_next_kilometer();
				printf("Pendant votre fuite, un zombie vous a lacéré une partie du corps !\nIl faut quitter cet enfer et vite !!\n");
			}
		}
	}
	wait_user();
}


void Die4laugh::a_try_to_kill()
{
	clean();
	
	if (terror == true) printf("Impossible de vous battre, vous êtes littéralement tétanisé(e) !\n"); else
	{
		if (energy <= 0)
		{
			printf("Vous n'avez pas assez d'énergie pour vous battre.\n");
		} 
		else
		{
			if (rand()%8==0)
			{
				monsters --;
				printf("Au terme d'un effroyable affrontement, vous avez finalement réussi à faire chuter un zombie contre un rocher...\nSa tête a littéralement explosé et son contenu s'est répandu sur vos chaussures ! Vous reculez en titubant, essouflé(e) : un de moins... Han ... han ...\n");
				stat_number_kills = stat_number_kills + 1;
				stat_number_hardkills++;
			}
			else
			{
				printf("Vous agrippez à pleines mains l'une des horribles créature mort-vivantes, le contact poisseux et collant de ses chairs putréfiées est insupportable...\nVous luttez, tentez de la repousser, mais rien n'y fait... Elle manque plusieurs fois de vous mordre ! Vous reculez, essouflé(e) et démoralisé(e)...\n");
			}
			energy --;
		}
	}
	wait_user();
}


void Die4laugh::display_actions()
{
	if (deep_mode == false)
	{
        printf("[U] Utiliser un objet dans mon sac\n");
	}
	
	if (drained == false && deep_mode == false && location.compare("Campement") != 0 && stuck == false)
	{
        printf("[I] Inspecter les environs\n");
	}
	
	if (location.compare("Désert...") != 0 && location.compare("Campement") != 0 && location.compare("Désert (zone épuisé)") != 0 && drained_location == false && deep_mode == false)
	{
        printf("[F] Fouiller %s\n",location.c_str());
	}
	
	if (deep_mode == false && stuck == false && energy > 0)
	{
		printf("[A] Avancer\n");
	}
	
	if (deep_mode == false && location.compare("Campement") == 0)
	{
		printf("[D] Dormir\n");
	}
	
	if (deep_mode == false && location.compare("Campement") != 0)
	{
		printf("[C] Camper (%.2f%% de survie)\n",survival_chance_ouside);
	}
	
	if (deep_mode == true)
	{
		printf("[Q] Quitter\n");
	}
	
	if (deep_mode == false && location.compare("Campement") != 0 && stuck == false)
	{
		printf("[R] Retour au campement");
		if (kilometers != 0) {printf(" (%d énergie)",energy_to_brb);}
		printf("\n");
	}
	
	if (deep_mode == false && location.compare("Campement") == 0)
	{
		printf("[C] Chantiers\n");
	}
	
	if (deep_mode == false && location.compare("Campement") == 0 && ch_waterwell == true && waterwell_today == false)
	{
		printf("[P] Prendre mon eau au puits\n");
	}
	
	if (deep_mode == false && location.compare("Campement") != 0 && stuck == true)
	{
		printf("[P] Prendre la fuite (danger)\n");
	}
	if (deep_mode == false && location.compare("Campement") != 0 && stuck == true)
	{
		printf("[B] Se battre à main nues (-1 énergie)\n");
	}
	
	if (deep_mode == false && location.compare("Campement") == 0 && ch_workshop == true)
	{
		printf("[T] Atelier\n");
	}
}


void Die4laugh::wait_for_action()
{
	std::string choice;
	int int_choice;

	printf("> ");
	std::cin >> choice; // input de la string
	
	if (choice.at(0) == '0' || choice.at(0) == '1' || choice.at(0) == '2' || choice.at(0) == '3' || choice.at(0) == '4' || choice.at(0) == '5' || choice.at(0) == '6' || choice.at(0) == '7' || choice.at(0) == '8' || choice.at(0) == '9')
	{
		std::stringstream ss;  
		ss << choice;  
		ss >> int_choice;  // convertit les caractères rentrés en int si c'est un nombre
		
		if (deep_mode == false)
 		{
			if (choice[choice.length()-1] == '*' && int_choice <= bag_size)
			{
				use_item(int_choice);
			}
			else
			{
				move_item(int_choice);
			}
	    }
	    if (deep_mode == true)
 		{
			if (terror == true && print_item(bag[int_choice-1],2).compare("19") != 0 && location.compare("Campement") != 0)  {printf("Impossible d'utiliser cet objet, vous êtes littéralement tétanisé(e) !\n"); wait_user();}
			else
			{
				use_item(int_choice);
				deep_mode = false;
			}
	    }
	}
	else
	{
		if (deep_mode == true)
		{
			if (choice.compare("q") == 0 || choice.compare("Q") == 0)
			{
				deep_mode = false;
				display_base();
			}
		}
		else
		{
			if (choice.compare("u") == 0 || choice.compare("U") == 0)
			{
				a_use_items();
			}
			if (choice.compare("i") == 0 || choice.compare("I") == 0)
			{
				if (drained == false && location.compare("Campement") != 0 && stuck == false)
				{
					a_dig_items();
				}
			}
			if (choice.compare("f") == 0 || choice.compare("F") == 0)
			{
				if (location.compare("Désert...") != 0 && location.compare("Campement") != 0 && location.compare("Désert (zone épuisé)") != 0 && drained_location == false && deep_mode == false)
				{
					a_dig_location_items();
				}
			}
			if (choice.compare("a") == 0 || choice.compare("A") == 0)
			{
				if (stuck == false)
				{
					a_next_kilometer();
				}
			}
			if (choice.compare("d") == 0 || choice.compare("D") == 0)
			{
				if (location.compare("Campement") == 0)
				{
					a_sleep_home();
				}
			}
			if (choice.compare("c") == 0 || choice.compare("C") == 0)
			{
				if (location.compare("Campement") != 0)
				{
					a_sleep_outside();
				}
			}
			if (choice.compare("r") == 0 || choice.compare("R") == 0)
			{
				if (location.compare("Campement") != 0 && stuck == false)
				{
					a_back_to_home();
				}
			}
			if (choice.compare("c") == 0 || choice.compare("C") == 0)
			{
				if (location.compare("Campement") == 0)
				{
					a_builds_camp();
				}
			}
			if (choice.compare("p") == 0 || choice.compare("P") == 0)
			{
				if (deep_mode == false && location.compare("Campement") == 0 && ch_waterwell == true && waterwell_today == false)
				{
					a_ch_waterwell();
				}
			}
			if (choice.compare("p") == 0 || choice.compare("P") == 0)
			{
				if (deep_mode == false && location.compare("Campement") != 0 && stuck == true)
				{
					a_runaway();
				}
			}
			if (choice.compare("b") == 0 || choice.compare("B") == 0)
			{
				if (deep_mode == false && location.compare("Campement") != 0 && stuck == true)
				{
					a_try_to_kill();
				}
			}
			if (choice.compare("a") == 0 || choice.compare("A") == 0)
			{
				if (deep_mode == false && location.compare("Campement") == 0 && ch_workshop == true)
				{
					a_ch_workshop();
				}
			}
		}
	}
}


void Die4laugh::stuck_f()
{
	if (terror == true)
		monsters_control = 0;
	else
		monsters_control = 3;
	if (monsters > monsters_control)
	{
		printf("\n/!\\ Attention, vous avez perdu le contrôle face aux zombies ! /!\\\n");
		stuck = true;
	}
	else
	{
		stuck = false;
	}
}


void Die4laugh::new_day()
{
	int rand_number;
	int i;
	int do_you_have_mine = 0;
	int z_increment;
	int z_inside;
	
	clean();
	
	// mort dans son lit
	if (location.compare("Campement") == 0)
	{
		if (z_attack > (display_camp_def)) // si les défenses ne sont pas assez solides
		{
			do_you_have_mine = count_camp_item(85); // nb mine
			
			rand_number = rand()%100;
			z_inside = z_attack-display_camp_def; // zombies rentrés
			rand_number = rand()%10+1;
			
			if (z_inside > rand_number) // MORT
			{
				if (do_you_have_mine >= 1 && z_inside < 53) // sauvé par la mine si pas trop de zombies rentrés
				{
					printf("Ils s'en sont pris à vous, ils sont rentrés dans le campement ! Un gros bruit a retenti, puis plus rien.\nLe petit groupe de zombies intrusif a marché sur une mine et cela vous a sauvé la vie !\n");
					remove_camp_item(85,1);
					if ((count_camp_item(85) > 1 || count_camp_item(47) > 1) && rand()%2 == 0) // pas de chance (succès explosif)
					{
						printf("\nCependant, mauvaise nouvelle : les autres explosifs du campement n'ont pas vraiment appréciés l'explosion.\n");
						wait_user();
						death(7);
					}
				}
				else if ((rand()%4 == 0) && terror == false)
				{
					printf("Nous avons deux nouvelles à vous annoncer. La bonne : malgré les tentatives de %d zombie(s) pour vous dévorer, vous avez tenu bon !\nLa mauvaise : l'expérience ayant été terrifiante, vous êtes désormais terrorisé(e) à l'idée d'avoir à vivre cela une seconde fois...\n",z_inside);
					terror = true;
				}
				else
				{
					death(6);
				}
			}
			else if (z_inside > 15 && ground[rand_number] != 0)
			{
				printf("Vous avez vraiment eu très très chaud aux fesses cette nuit ! Vous les avez entendu grogner, frapper voire hurler dehors.\nVos barricades ont fini par céder et vous vous êtes réfugié(e) sous votre %s, serrant contre vous vos bibelots, pour ne plus penser à rien. Puis ils sont repartis...\nTremblant(e) de peur, vous avez finalement quitté votre cachette, bien heureux(se) d'avoir survécu.",print_item(ground[rand_number],0).c_str());
			}
		}
	}
	
	// mort desydratation
	if (water_day == false)
	{
		if (big_thirst == true)
		{
			// printf("%p\n",&new_day);
			// printf("%p\n",&death);
			death(3);
		}
		else if (thirst == true)
		{
			big_thirst == true;
			thirst = false;
		}
		else
		{
			thirst = false;
		}
	}
	
	// blessure -> infection
	if (injury == true)
	{
		ill = true;
	}
	
	// camping mort
	if (camping == true)
	{
		rand_number = rand()%99+1;
		//printf("NB ALEATOIRE : %d, CHANCE : %f",rand_number,survival_chance_ouside);
		if (rand_number > survival_chance_ouside)
		{
			death(1);
		}
	}
	
	// mort dependance
	if (dependant == true && drug_day == false)
	{
		death(2);
	}
	
	// mort infecte
	if (ill == true)
	{
		if (rand()%5 < 2) // 2 chance sur 5
		{
			death(5);
		}
	}
	
	/*survival_chance_ouside = (100*(kilometers/10.0)) *  (1/(days*0.5)); // refresh at display
	survival_chance_ouside = survival_chance_ouside + day_outside*5; // jour passé dehors baisse les chances
	if (survival_chance_ouside >= 100) {survival_chance_ouside = 100;}*/
	
	//decheance des defenses
	/*if (days > 2)
	{
		camp_def = camp_def - (rand()%5 * days/3);
	}*/
	
	//eteint les torches
	for (int i=0; i<bag_size; i++)
	{
		if (bag[i] == 68)
			bag[i] = 69;
	}
	for (int i=0; i<ground_size; i++)
	{
		if (ground[i] == 68)
			ground[i] = 69;
	}
	
	//mirador
	if (ch_watchtower == true)
	{
		for (i=0; i<sizeof(kilometers_exhausted)/(sizeof(kilometers_exhausted[0])); i++)
		{
			if (kilometers_exhausted[i] >= 13)
				kilometers_exhausted[i] = rand()%20+1;
		}
	}
	
	//decorations
	for (int i=0; i<ground_size; i++)
	{
		decoration = decoration + atoi(print_item(ground[i],5).c_str());
	}
	
	// cuisine
	if (ch_cuisine > 0)
	{
		int chance_cook = 33;
		if (ch_cuisine == 2) chance_cook = 66;
		if (ch_cuisine == 3) chance_cook = 99;
		i = 0;
		while (ground[i] != 0)
		{
			if (print_item(ground[i],2).compare("3") == 0)
			{
				if (ground[i] != 102 && ground[i] != 103 && ground[i] != 104 && ground[i] != 105 && ground[i] != 106 && ground[i] != 100 && ground[i] != 147)
				{
					if (rand()%100+1 > chance_cook)
						ground[i] = 147;
					else
						ground[i] = 105; // plat réussi
				}
			}
			i++;
		}
	}
	
	// potager
	if (ch_vegetable == true)
	{
		int melon = rand()%2;
		int legume = rand()%2;
		add_camp_item(100,melon);
		add_camp_item(101,legume);
	}
	
	days = days + 1;
	
	water_day = false;
	food_day = false;
	drug_day = false;
	convalescent = false;
	energy = energy_max;
	waterwell_today = false;
	meds = false;
	drained = false;
	drained_location = false;
	z_attack = rand()%6+1 * days*3;
	monsters = 0;
	
	if (alcohol == true) {alcohol = false; hangover = true;}
	else if (hangover == true) {hangover = false;}
	
	printf("\n\n---------------\nJOUR %d\n---------------\n\n",days);
	wait_user();
}


void Die4laugh::death(int why)
{
	int choice, i, j, a;
	std::string b;
	clean();
	
	
	printf("\n\n\n\nFélicitations, vous êtes mort(e) !!\n\n");
	if (why == 1)
	{
		printf("\"Peu après minuit, un silence pesant s'est abattu tout autour de vous, comme si toute vie venait de s'éteindre\nbrusquement. La nuit s'est faite glaciale... Puis vous les avez vus, des dizaines... des centaines titubant\nvers vous.. Leurs mains vous saisissant, agrippant, tirant, arrachant... Puis ils vous ont traîné\navec eux toute la nuit, pour vous dévorer encore vivant au petit matin.\"");
		stat_number_death_outside++;
	}
	else if (why == 2)
	{
		printf("Les drogues c'est agréable quand on en a. Dès qu'on a épuisé ses réserves, c'est une autre histoire... D'abord\non tremble, puis on commence à se vider de son contenu toutes les dix minutes. Quand la situation de\nmanque empire, on finit par perdre totalement la raison. C'est comme ça qu'on se retrouve à avaler des\ncailloux en pensant avoir trouvé des stéroïdes.");
		stat_number_death_drugs++;
	}
	else if (why == 3)
	{
		printf("Le manque d'eau est réellement quelque chose de sale. Durant vos dernières heures, votre peau a commencé à se\ndessécher et à se craqueler, puis votre langue a gonflé. vous avez bien essayé de trouver n'importe quoi\nà boire. Sans succès. Certains diront même vous avoir vu en train d'avaler du sable à pleines poignées avant\nde vous effondrer, raide mort(e).");
		stat_number_death_water++;
	}
	else if (why == 4)
	{
		printf("Argh ! On dirait bien qu'une silhouette s'était glissée derrière vous ! Sans avoir eu le temps de réagir, quelqu'un,\nou quelque chose s'est jeté sur vous, vous a roué de coups avant de vous dévorer alors que vous étiez encore conscient(e).\nAvant de sombrer dans la mort, une question vous a assailli : quel goût pouvez-vous bien avoir ?");
		stat_number_death_outside++;
	}
	else if (why == 5)
	{
		printf("Petit à petit, l'horrible maladie vous a rongé de l'intérieur... Rapidement, des signes de l'infection sont apparus sur votre corps :\nplaies, hématomes, chairs qui se décomposent... Jusqu'à l'agonie finale qui aura duré plusieurs heures cette nuit.\nLa mort en est presque un soulagement.");
		stat_number_death_ill++;
	}
	else if (why == 6)
	{
		printf("Cloîtré dans votre campement, vous espériez qu'ils ne passeraient pas... Vous les avez entendus grogner, renifler à votre porte...\nPuis plus rien. Une cloison proche a alors brusquement volé en éclats. Mal barricadée sûrement...\nVous avez hurlé, ils vous ont laissé vous débattre puis vous ont plaqué contre votre lit.\nLentement, ils vous ont dévoré. Aucun survivant n'est venu à votre aide. Personne.");
		stat_number_death_inside++;
	}
	else if (why == 7)
	{
		printf("Les créatures de ce monde ne vous aimaient pas. Les zombies, comme les survivants, cherchant à vous éviter. Enfin, pas cette nuit.\nDeux d'entre eux vous ont violemment sauté dessus, tandis que deux autres ont sauté sur une mine.\nL'explosion s'est étendue sur certains objets et détruit le campement ainsi que tout ce qui était en son sein.\nC'est ce qu'on appelle partir en beauté.");
		stat_number_death_bomb++;
	}
	else if (why == 8)
	{
		printf("Plutôt que continuer à vivre dans ce monde de losers, vous avez fait le choix de vous simplifier la vie...\nEn l'écourtant un peu. Bof, après tout, une journée de plus ou de moins...");
		stat_number_death_suicide++;
	}
	if (days > stat_max_days)
		stat_max_days = days;
	if (kilometers > stat_max_killometers)
		stat_max_killometers = kilometers;
	stat_number_killometers = stat_number_killometers + kilometers;
	if (display_camp_def > stat_max_def)
		stat_max_def = display_camp_def;
	// printf("OK");
	// printf("%d > %d\n",days,stat_max_days);
	stat_number_decoration = stat_number_decoration + decoration;
	total_days = days + total_days;
	fstat_write();
	
	
	printf("\n\n\n\nTOP ACTIVITEES JOUEURS :\n");
	int number_days[500];
	std::string number_days_str[500];
	for (i=0; i<500; i++) number_days[i] = 0;
	std::fstream the_file;
	// printf("0"); wait_user();
	decrypt();
	the_file.open("save.csv",std::ios::in);
	// printf("1"); wait_user();
	// récupération données //
	if (the_file.is_open())
	{ 
		std::string line;
		std::string delimiter = ",";
		i = 0;
		getline(the_file, line); // pass la premiere ligne
		while (getline(the_file, line))
		{
			// printf("3");
			std::stringstream line_to_split(line);
			std::string segment;
			std::vector<std::string> seglist;
			while(std::getline(line_to_split, segment, ',')) // cree un std::vector<std::string> seglist{ élements };
			{
				//printf("element = %s\n",segment.c_str());
				//printf("Ajout dans le tableau segment\n");
				seglist.push_back(segment);
				//printf("OK\n");
				//printf("\n\n");
			}
			number_days[i] = atoi(seglist[26].c_str());
			number_days_str[i] = (seglist[0].c_str());
			i++;
			// printf("4");
		}
		the_file.close();
	}
	// printf("5"); wait_user();
	for (i = 0; i < 499; ++i)  // sort
	{
		for (j = i + 1; j < 499; ++j)
		{
			if (number_days[i] < number_days[j]) 
				{
					a = number_days[i];
					b = number_days_str[i];
					number_days[i] = number_days[j];
					number_days_str[i] = number_days_str[j];
					number_days[j] = a;
					number_days_str[j] = b;
				}
		}
	}
	// printf("6"); wait_user();
	for (i=0; i<=9; i++)
	{
		if (number_days[i] > 0)
			printf("%d- %s (%d jours)\n",(i+1),number_days_str[i].c_str(), number_days[i]);
	}
	Sleep(200);
	encrypt();
	
	printf("\n\n\nVous avez survécu %d jours. Voulez vous retourner au menu ?\n[1] Oui\n[x] Non\n> ",days);
	scanf("%d",&choice);

	if (choice == 1)
	{
		Die4laugh the_game;
	}
	else
	{
		exit(0);
	}
}


void Die4laugh::refresh_at_display()
{
	if (location.compare("Campement") == 0)
	{
		camp_defadd = 0;
		for (int i=0; i<ground_size; i++)
		{
			if (print_item(ground[i],2).compare("13") == 0)
			{
				camp_defadd = camp_defadd + 5;
			}
		}
	}
	if (monsters < 0) monsters = 0;
	display_camp_def = camp_def + camp_defadd;
	if (display_camp_def < 0) display_camp_def = 0;
	// if (display_camp_def > 100) display_camp_def = 100;
	if (z_attack < 0) z_attack = 0;
	
	survival_chance_ouside =  ( (100*(kilometers/10.0)) * (1/(days*0.5)) ) / (monsters);
	if (terror == true) {survival_chance_ouside = survival_chance_ouside-90;}
	//printf("%f * %f = %f",(100*(kilometers/10.0)),(1/(days*0.5)),survival_chance_ouside);
	if (survival_chance_ouside >= 100) {survival_chance_ouside = 100;}
	if (survival_chance_ouside <= 0) {survival_chance_ouside = 0;}
	
	if (injury == true)
		energy_max = 5;
	else
		energy_max = 6;
	
	// gestion slots supplémentaires
	slot1 = false; slot2 = false;
	for (int i=0; i<bag_size; i++)
	{
		if (print_item(bag[i],0).compare("Sac supplémentaire") == 0 || print_item(bag[i],0).compare("Ceinture à poches") == 0)
			slot1 = true;
		if (print_item(bag[i],0).compare("Sac super-pratique") == 0 || print_item(bag[i],0).compare("Caddie") == 0)
			slot2 = true;
	}
	if (slot1 == true)
		bag_size = 7;
	else if (slot2 == true)
		bag_size = 8;
	else
		bag_size = 5;
	
	make_my_ground_firstindex();
	sort_bag_alphabet();
	sort_ground_index();
	stuck_f();
}


void Die4laugh::display_base()
{
	bool done = false;
	while (!done)
	{
		clean();
		
		// affichage
		if (location.compare("Campement") == 0) printf("\n                           (   )\n                          (    )\n                           (    )\n                          (    )\n                            )  )\n                           (  (                  /\\\n                            (_)                 /  \\  /\\\n                    ________[_]________      /\\/    \\/  \\\n           /\\      /\\        ______    \\    /   /\\/\\  /\\/\\\n          /  \\    //_\\       \\    /\\    \\  /\\/\\/    \\/    \\\n   /\\    / /\\/\\  //___\\       \\__/  \\    \\/\n  /  \\  /\\/    \\//_____\\       \\ |[]|     \\\n/\\/\\/\\/       //_______\\       \\|__|      \\\n/      \\      /XXXXXXXXXX\\                  \\\n        \\    /_I_II  I__I_\\__________________\\\n               I_I|  I__I_____[]_|_[]_____I\n               I_II  I__I_____[]_|_[]_____I\n               I II__I  I     XXXXXXX     I\n            ~~~~~"   "~~~~~~~~~~~~~~~~~~~~~~~~");
		else if (location.compare("Désert...") == 0) printf("\n                /||\\\n                ||||\n                ||||\n                |||| /|\\\n           /|\\  |||| |||\n           |||  |||| |||\n           |||  |||| |||\n           |||  |||| d||\n           |||  |||||||/\n           ||b._||||~~'\n           \\||||||||\n            `~~~||||\n                ||||\n                ||||\n~~~~~~~~~~~~~~~~||||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n  \\/..__..--  . |||| \\/  .  .. . \\/         \\/ \\/ .. \\/ \\/   .  . \\/ \n\\/         \\/ \\/    \\/     ..          . . \\/  ..    \\/  .   .  \\/   \n        .  \\/              \\/    .  \\/..__..--  .      \\/  .   .   \\/\n. \\/             .   \\/     .     \\/  .   .    \\/   \\/    \\/     ..  \n   __...--..__..__       .     \\/         .  \\/       \\/     .     \\/\n\\/  .   .    \\/     \\/    __..--..\\/         \\/ \\/   . . ___--..__. .");
		else if (location.compare("Désert (zone épuisé)") == 0) printf("\n                /||\\\n                ||||\n                ||||\n                |||| /|\\\n           /|\\  |||| |||\n           |||  |||| |||\n           |||  |||| |||\n           |||  |||| d||\n           |||  |||||||/\n           ||b._||||~~'\n           \\||||||||\n            `~~~||||\n                ||||\n                ||||\n~~~~~~~~~~~~~~~~||||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n    ..__..--  . ||||     .  .. .                  ..         .  .    \n                           ..          . .     ..        .   .       \n        .                        .    ..__..--  .          .   .     \n.                .          .         .   .                      ..  \n   __...--..__..__       .                .                  .       \n    .   .                 __..--..                   . . ___--..__. .");
		else printf("\n                  .e$c\"*eee...                    \n                z$$$$$$.  \"*$$$$$$$$$.                    \n            .z$$$$$$$$$$$e. \"$$$$$$$$$$c.                 \n         .e$$P\"\"  $$  \"\"*$$$bc.\"$$$$$$$$$$$e.             \n     .e$*\"\"       $$         \"**be$$$***$   3             \n     $            $F              $    4$r  'F            \n     $           4$F              $    4$F   $            \n    4P   \\       4$F              $     $$   3r           \n    $\"    r      4$F              3     $$r   $           \n    $     '.     $$F              4F    4$$   'b          \n   dF      3     $$    ^           b     $$L   \"L         \n   $        .    $$   %            $     ^$$r   \"c        \n  JF             $$  %             4r     '$$.   3L       \n .$              $$ \"               $      ^$$r\"\"         \n $%              $$P                3r  .e*\"              \n'*=*********************************$$P\"");
		
		//actualisation chaque tour
		refresh_at_display();
		printf("\n\n\n\n\nJour		: %d\n",days);
		if (kilometers != 0) {printf("Kilomètres	: %d\n",kilometers);}
		printf("Energie		: %d/%d\n",energy,energy_max);
		printf("Lieu		: %s",location.c_str());
		if (location.compare("Campement") != 0) {if (terror == false) printf("\nZombies		: %d / %d",monsters,monsters_control); else printf("\nZombies		: %d / TERRORISE(E)",monsters);}
		else {printf(" (Attaque : %d   Défenses : %d)\n",z_attack,display_camp_def);}
		printf("\nMes états :\n");
		display_states();
		printf("\n\nMon sac :\n");
		display_bag();
		printf("\nAu sol : \n");
		display_ground();
		printf("\n\nVos actions :\n");
		display_actions();
		wait_for_action();
	}
}


int main(int argc, char** argv)
{
	setlocale(LC_CTYPE, "fra");
	srand(time(NULL));
	
	clean();
	printf("Une guerre atomique mondiale faisait rage. Quand arrivèrent les E-bombs, le nombre de morts augmenta drastiquement\net la destruction du monde tel que nous le connaissions s'aggrava. Avec la radioactivité et les\nondes sur la Terre, la flore commença à décroître. Ainsi, de grands déserts se formèrent et la\nflore ayant résisté à une telle catastrophe se transforma petit à petit. Les hommes, eux, se cachèrent dans leurs abris\nanti-atomique ou dans des zones loin des explosions.\n\nC'est dans la colline de Molineux-Les-Bains que fut découvert l'origine d'un fléau pis encore ! Il\ns'agissait d'une personne que beaucoup de gens appréciaient énormément pour sa gentillesse et sa\ngénérosité que quelques citoyens de cette petite communauté, formée à la suite de ces catastrophes,\ndécouvrirent dans son taudis complètement décomposée sur le sol. Quand ces citoyens voulurent s'approcher de\nlui afin de le transporter et l'incinérer, le putride se réveilla. Il s'agissait du premier zombie !\n\nCette personne à l'origine humaine semblait touchée par une forme de rage provoquant la mort d'une grande partie de\nson corps. Le cannibalisme impulsif faisant partie intégrante du zombie, il mange toutes les\npersonnes qu'il peut. Ceci provoqua une terrible épidémie qui débuta dans le taudis de ce premier zombie puisque\nune morsure suffisait à contaminer une personne.\n\nCe terrible virus contamina les survivants de la guerre, laissant encore moins d'Êtres humains sur Terre. Les\nderniers survivants sont alors forcés de piller les anciens vestiges de l'humanité pour survivre. \n\n\n\n");
	wait_user();
	
	Die4laugh the_game;
	
	return 0;
}
