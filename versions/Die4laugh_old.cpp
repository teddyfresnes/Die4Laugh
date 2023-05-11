#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <cwctype>

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
// total_hours_wasted_here = 27
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
	int key = 53;
    // Input stream
	std::rename("save.csv", "save_old.csv");
	
    std::fstream fin; //File to read from
    std::fstream fout; //Temporary file
 
    fin.open("save_old.csv", fstream::in);
    fout.open("save.csv", fstream::out);
 
    // Reading original file till
    // end of file
    while (fin >> noskipws >> c)
	{
        int temp = (c + key);
 
        // Write temp as char in
        // output file
        fout << (char)temp;
    }
 
    // Closing both files
    fin.close();
    fout.close();
}
 

void decrypt()
{
	int key = 53;
	
	std::rename("save.csv", "save_old.csv");
    std::fstream fin;
    std::fstream fout;
    fin.open("save_old.csv", fstream::in);
    fout.open("save.csv", fstream::out);
 
    while (fin >> noskipws >> c) {
 
        // Remove the key from the
        // character
        int temp = (c - key);
        fout << (char)temp;
    }
 
    fin.close();
    fout.close();
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
		int ground[500];
		int ground_home[500];
		int ground_size;
		bool deep_mode;
		bool drained;
		bool drained_location;
		bool home;
		bool camping;
		float survival_chance_ouside;
		int day_outside;
		bool stuck;
		int kilometers_exhausted[500];
		int camp_def;
		int camp_defadd;
		int display_camp_def;
		bool slot1;
		bool slot2;
		
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
		bool waterwell_today;
		bool ch_workshop;
		int workshop_energy;
		
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
		int stat_number_death_outside;
		int stat_number_death_inside;
		int stat_number_death_drugs;
		int stat_number_death_water;
		int stat_number_death_ill;
		int stat_number_death_suicide;
		int stat_number_death_bomb;
		int stat_success_chainsaw;
		int stat_success_cardoor;
		
				
	public:
		// constructeur
		Die4laugh();
		
		// m�thodes
		void sort_empty_racism(int * my_array, int size);
		
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
	ground[1] = 0;
	ground[2] = 0;
	ground[3] = 0;
	ground[4] = 0;
	ground[5] = 0;
	ground[6] = 0;
	ground[7] = 0;
	ground[8] = 0;
	ground[9] = 0;
	deep_mode = false;
	drained = false;
	drained_location = false;
	home = true;
	camping = false;
	survival_chance_ouside = 0.0f;
	day_outside = 0;
	stuck = false;
	ch_workshop = false;
	workshop_energy = 3;
	ch_waterwell = false;
	waterwell_today = false;
	for (i=0; i<sizeof(kilometers_exhausted)/(sizeof(kilometers_exhausted[0])); i++)
	{
		kilometers_exhausted[kilometers] = rand()%3;
	}
	camp_def = 100;
	camp_defadd = 0;
	slot1 = false;
	slot2 = false;
	
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
	
	if (position_empty <= last_position && position_empty != (-1) && last_position != (-1)) // pour ne pas depasser apr�s la derni�re position trouv� + si pas de position trouv�
	{
		my_array[position_empty] = my_array[last_position];
		my_array[last_position] = 0;
	}
}


void Die4laugh::fstat_get(std::string username)
{
	decrypt();
	
	/* v�rifier si le profil existe, sinon il le cr�e */
	
	std::fstream the_file;
	int i;
	int number_columns;
	int name_index = -1;
	bool name_not_find = true;
	std::string file_name = "save.csv";
	
	std::ifstream f(file_name.c_str());
	if (f.good() == false) // cr�e le fichier si il n'existe pas
	{
		std::ofstream MyFile("save.csv");
		MyFile << "name,max_days,max_kilometers,kilometers,drugs,alcohol,kills,hardkills,brokenitems,crafteditems,death_outside,death_inside,death_drugs,death_water,death_ill,death_suicide,death_bomb,chainsaw,cardoor\n";
		MyFile.close();
	}
	
	the_file.open("save.csv",std::ios::in);
	
	/* check if le pseudo exist */
	if (the_file.is_open())
	{ //checking whether the file is open
		std::string first_line;
		getline(the_file, first_line);
		number_columns = std::count(first_line.begin(), first_line.end(), ',');
		
		the_file.close(); //close the file object.
	}
	
	the_file.open("save.csv",std::ios::in);
	if (the_file.is_open())
	{ //checking whether the file is open
		std::string line;
		std::string delimiter = ",";
		i = 0;
		while(getline(the_file, line))
		{ //read data from file object and put it into string.
			//printf("\n\ni = %d\n",i);
			//std::cout << line << ""; //print the data of the string
			std::string name = line.substr(0, line.find(delimiter)); // pseudo
			name_not_find = name.compare(username);
			if (!name_not_find) // si le nom est trouv�
			{
				//printf("trouv� � %d",i);
				name_index = i;
				index_save = i;
				break;
			}
			i++;
		}
		the_file.close(); //close the file object.
	}
	//printf("last : %d, index = %d, not_find = %d",i,name_index,name_not_find);
	
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
	
	the_file.open("save.csv",std::ios::in);
	
	/* r�cup�ration donn�es */
	if (the_file.is_open())
	{ 
		std::string line;
		std::string delimiter = ",";
		i = -1;
		while (i != index_save && getline(the_file, line))
		{
			i++;
		}
		
		std::stringstream line_to_split(line);
		std::string segment;
		std::vector<std::string> seglist;
		while(std::getline(line_to_split, segment, ',')) // cree un std::vector<std::string> seglist{ �lements };
		{
		   seglist.push_back(segment);
		}

		stat_max_days = atoi(seglist[1].c_str());
		//printf("ligne : %s str first : %s d\n",line.c_str(),seglist[1].c_str(),atoi(seglist[1].c_str()));
		stat_max_killometers = atoi(seglist[2].c_str());
		//printf("ligne : %s str 2 : %s d\n",line.c_str(),seglist[2].c_str(),atoi(seglist[2].c_str()));
		stat_number_killometers = atoi(seglist[3].c_str());
		stat_number_drugs = atoi(seglist[4].c_str());
		stat_number_alcohol = atoi(seglist[5].c_str());
		stat_number_kills = atoi(seglist[6].c_str());
		stat_number_hardkills = atoi(seglist[7].c_str());
		stat_number_brokenitems = atoi(seglist[8].c_str());
		stat_number_crafteditems = atoi(seglist[9].c_str());
		stat_number_death_outside = atoi(seglist[10].c_str());
		stat_number_death_inside = atoi(seglist[11].c_str());
		stat_number_death_drugs = atoi(seglist[12].c_str());
		stat_number_death_water = atoi(seglist[13].c_str());
		stat_number_death_ill = atoi(seglist[14].c_str());
		stat_number_death_suicide = atoi(seglist[15].c_str());
		stat_number_death_bomb = atoi(seglist[16].c_str());
		stat_success_chainsaw = atoi(seglist[17].c_str());
		stat_success_cardoor = atoi(seglist[18].c_str());
		
		std::string name = line.substr(0, line.find(delimiter)); // pseudo
		name_not_find = name.compare(username_input);
		
		the_file.close(); //close the file object.
	}
	
	encrypt();
}


void Die4laugh::fstat_write()
{
	decrypt();
	
	printf("stat kilometers : stat_number_killometers %d",stat_number_killometers);
	std::string line_to_write = username_input
		+ "," + patch::to_string(stat_max_days) + "," + patch::to_string(stat_max_killometers) + "," + patch::to_string(stat_number_killometers) + "," + patch::to_string(stat_number_drugs) + "," + patch::to_string(stat_number_alcohol) + "," + patch::to_string(stat_number_kills)
		+ "," + patch::to_string(stat_number_hardkills) + "," + patch::to_string(stat_number_brokenitems) + "," + patch::to_string(stat_number_crafteditems) + "," + patch::to_string(stat_number_death_outside) + "," + patch::to_string(stat_number_death_inside) + "," + patch::to_string(stat_number_death_drugs)
		+ "," + patch::to_string(stat_number_death_water) + "," + patch::to_string(stat_number_death_ill) + "," + patch::to_string(stat_number_death_suicide) + "," + patch::to_string(stat_number_death_bomb) + "," + patch::to_string(stat_success_chainsaw) + "," + patch::to_string(stat_success_cardoor);

	std::rename("save.csv", "save_old.csv");
    std::ifstream filein("save_old.csv"); //File to read from
    std::ofstream fileout("save.csv"); //Temporary file
    if(!filein || !fileout)
    {
        std::cout << "problem with save" << std::endl;
    }

    std::string strTemp;
    while(filein >> strTemp)
    {
		if (strTemp.find(username_input) != std::string::npos)
		{
			printf("TROUVER TRERE");
            strTemp = line_to_write;
        }
        strTemp += "\n";
        fileout << strTemp;
        //if(found) break;
    }
	std::remove("save_old.csv");
	
	encrypt();
}


void Die4laugh::fstat_profile(std::string username)
{
	if (username.compare("- -") == 1)
	{
		clean();
		
		fstat_get(username); // recupere les stats dans les variables
		
		printf("Profil de %s\n\n",username.c_str());
		printf("Statistiques :\n");
		printf("{%d} Nombre de jours surv�cus au maximum\n",stat_max_days);
		printf("{%d} Distance maximum parcourue\n",stat_max_killometers);
		printf("{%d} Distance totale parcourue\n",stat_number_killometers);
		printf("{%d} Nombre de drogues utilis�es\n",stat_number_drugs);
		printf("{%d} Nombre d'alcool ing�r�\n",stat_number_alcohol);
		printf("{%d} Nombre de zombies tu�s\n",stat_number_kills);
		printf("{%d} Nombre de zombies tu�s � mains nus\n",stat_number_hardkills);
		printf("{%d} Nombre d'objets cass�s\n",stat_number_brokenitems);
		printf("{%d} Nombre de fabrications � l'atelier\n",stat_number_crafteditems);
		printf("{%d} Mort(e) dehors\n",stat_number_death_outside);
		printf("{%d} Mort(e) dans le campement\n",stat_number_death_inside);
		printf("{%d} Mort(e) par d�pendance\n",stat_number_death_drugs);
		printf("{%d} Mort(e) d�sydrat�(e)\n",stat_number_death_water);
		printf("{%d} Mort(e) par maladie\n",stat_number_death_ill);
		printf("{%d} Mort(e) par suicide\n",stat_number_death_suicide);
		printf("\nSucc�s :\n");
		printf("{%d} Terroriste (Mort(e) explos�)\n",stat_number_death_bomb);
		printf("{%d} Massacre � la tron�onneuse\n",stat_success_chainsaw);
		printf("{%d} Apprenti m�canicien\n",stat_success_cardoor);
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
	stat_number_death_outside = 0;
	stat_number_death_inside = 0;
	stat_number_death_drugs = 0;
	stat_number_death_water = 0;
	stat_number_death_ill = 0;
	stat_number_death_suicide = 0;
	stat_number_death_bomb = 0;
	stat_success_chainsaw = 0;
	stat_success_cardoor = 0;
	
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
	std::string str_stat_number_death_outside = "- -";
	std::string str_stat_number_death_inside = "- -";
	std::string str_stat_number_death_drugs = "- -";
	std::string str_stat_number_death_water = "- -";
	std::string str_stat_number_death_ill = "- -";
	std::string str_stat_number_death_suicide = "- -";
	std::string str_stat_number_death_bomb = "- -";
	std::string str_stat_success_chainsaw = "- -";
	std::string str_stat_success_cardoor = "- -";
	
	decrypt();
	
	std::fstream the_file;
	
	the_file.open("save.csv",std::ios::in);

	/* r�cup�ration donn�es */
	if (the_file.is_open())
	{ 
		int i;
		std::string line;
		std::string delimiter = ",";
		i = -1;
		while (getline(the_file, line))
		{
			std::stringstream line_to_split(line);
			std::string segment;
			std::vector<std::string> seglist;
			while(std::getline(line_to_split, segment, ',')) // cree un std::vector<std::string> seglist{ �lements };
			{
			   seglist.push_back(segment);
			}

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
			if (atoi(seglist[10].c_str()) > stat_number_death_outside)
			{
				stat_number_death_outside = atoi(seglist[10].c_str());
				str_stat_number_death_outside = seglist[0].c_str();
			}
			if (atoi(seglist[11].c_str()) > stat_number_death_inside)
			{
				stat_number_death_inside = atoi(seglist[11].c_str());
				str_stat_number_death_inside = seglist[0].c_str();
			}
			if (atoi(seglist[12].c_str()) > stat_number_death_drugs)
			{
				stat_number_death_drugs = atoi(seglist[12].c_str());
				str_stat_number_death_drugs = seglist[0].c_str();
			}
			if (atoi(seglist[13].c_str()) > stat_number_death_water)
			{
				stat_number_death_water = atoi(seglist[13].c_str());
				str_stat_number_death_water = seglist[0].c_str();
			}
			if (atoi(seglist[14].c_str()) > stat_number_death_ill)
			{
				stat_number_death_ill = atoi(seglist[14].c_str());
				str_stat_number_death_ill = seglist[0].c_str();
			}
			if (atoi(seglist[15].c_str()) > stat_number_death_suicide)
			{
				stat_number_death_suicide = atoi(seglist[15].c_str());
				str_stat_number_death_suicide = seglist[0].c_str();
			}
			if (atoi(seglist[16].c_str()) > stat_number_death_bomb)
			{
				stat_number_death_bomb = atoi(seglist[16].c_str());
				str_stat_number_death_bomb = seglist[0].c_str();
			}
			if (atoi(seglist[17].c_str()) > stat_success_chainsaw)
			{
				stat_success_chainsaw = atoi(seglist[17].c_str());
				str_stat_success_chainsaw = seglist[0].c_str();
			}
			if (atoi(seglist[18].c_str()) > stat_success_cardoor)
			{
				stat_success_cardoor = atoi(seglist[18].c_str());
				str_stat_success_cardoor = seglist[0].c_str();
			}
		}
		
		the_file.close(); //close the file object.
	}
	
	encrypt();
	
	/*affichage*/
	printf("Meilleurs statistiques des joueurs :\n");
	printf("{%d} Nombre de jours surv�cus au maximum : %s\n",stat_max_days,str_stat_max_days.c_str());
	printf("{%d} Distance maximum parcourue : %s\n",stat_max_killometers,str_stat_max_killometers.c_str());
	printf("{%d} Distance totale parcourue : %s\n",stat_number_killometers,str_stat_number_killometers.c_str());
	printf("{%d} Nombre de drogues utilis�es : %s\n",stat_number_drugs,str_stat_number_drugs.c_str());
	printf("{%d} Nombre d'alcool ing�r� : %s\n",stat_number_alcohol,str_stat_number_alcohol.c_str());
	printf("{%d} Nombre de zombies tu�s : %s\n",stat_number_kills,str_stat_number_kills.c_str());
	printf("{%d} Nombre de zombies tu�s � mains nus : %s\n",stat_number_hardkills,str_stat_number_hardkills.c_str());
	printf("{%d} Nombre d'objets cass�s : %s\n",stat_number_brokenitems,str_stat_number_brokenitems.c_str());
	printf("{%d} Nombre de fabrications � l'atelier : %s\n",stat_number_crafteditems,str_stat_number_crafteditems.c_str());
	printf("{%d} Mort(e) dehors : %s\n",stat_number_death_outside,str_stat_number_death_outside.c_str());
	printf("{%d} Mort(e) dans le campement : %s\n",stat_number_death_inside,str_stat_number_death_inside.c_str());
	printf("{%d} Mort(e) par d�pendance : %s\n",stat_number_death_drugs,str_stat_number_death_drugs.c_str());
	printf("{%d} Mort(e) d�sydrat�(e) : %s\n",stat_number_death_water,str_stat_number_death_water.c_str());
	printf("{%d} Mort(e) par maladie : %s\n",stat_number_death_ill,str_stat_number_death_ill.c_str());
	printf("{%d} Mort(e) par suicide : %s\n",stat_number_death_suicide,str_stat_number_death_suicide.c_str());
	printf("\nMeilleures succ�s des joueurs:\n");
	printf("{%d} Terroriste (Mort(e) explos�) : %s\n",stat_number_death_bomb,str_stat_number_death_bomb.c_str());
	printf("{%d} Massacre � la tron�onneuse : %s\n",stat_success_chainsaw,str_stat_success_chainsaw.c_str());
	printf("{%d} Apprenti m�canicien : %s\n",stat_success_cardoor,str_stat_success_cardoor.c_str());
	printf("\n[X] Retour au menu\n");
	
	int choice;
	
	printf("Quel profil voulez vous regarder ?");
	printf("\n> ");
	scanf("%d",&choice);
	fflush(stdin);
	
	if (choice == 1) fstat_profile(str_stat_max_days);
	else if (choice == 2) fstat_profile(str_stat_max_killometers);
	else if (choice == 3) fstat_profile(str_stat_number_killometers);
	else if (choice == 4) fstat_profile(str_stat_number_drugs);
	else if (choice == 5) fstat_profile(str_stat_number_alcohol);
	else if (choice == 6) fstat_profile(str_stat_number_kills);
	else if (choice == 7) fstat_profile(str_stat_number_hardkills);
	else if (choice == 8) fstat_profile(str_stat_number_brokenitems);
	else if (choice == 9) fstat_profile(str_stat_number_crafteditems);
	else if (choice == 10) fstat_profile(str_stat_number_death_outside);
	else if (choice == 11) fstat_profile(str_stat_number_death_inside);
	else if (choice == 12) fstat_profile(str_stat_number_death_drugs);
	else if (choice == 13) fstat_profile(str_stat_number_death_water);
	else if (choice == 14) fstat_profile(str_stat_number_death_ill);
	else if (choice == 15) fstat_profile(str_stat_number_death_suicide);
	else if (choice == 16) fstat_profile(str_stat_number_death_bomb);
	else if (choice == 17) fstat_profile(str_stat_success_chainsaw);
	else if (choice == 18) fstat_profile(str_stat_success_cardoor);
}


void Die4laugh::display_day0() // gere l'initialisation pseudo et menu
{
	bool done = false;
	char tmp[20];
	int choice;

	clean();
	printf("Une guerre atomique mondiale faisait rage. Quand arriv�rent les E-bombs, le nombre de morts augmenta drastiquement\net la destruction du monde tel que nous le connaissions s'aggrava. Avec la radioactivit� et les\nondes sur la Terre, la flore commen�a � d�cro�tre. Ainsi, de grands d�serts se form�rent et la\nflore ayant r�sist� � une telle catastrophe se transforma petit � petit. Les hommes, eux, se cach�rent dans leurs abris\nanti-atomique ou dans des zones loin des explosions.\n\nC'est dans la colline de Molineux-Les-Bains que fut d�couvert l'origine d'un fl�au pis encore ! Il\ns'agissait d'une personne que beaucoup de gens appr�ciaient �norm�ment pour sa gentillesse et sa\ng�n�rosit� que quelques citoyens de cette petite communaut�, form�e � la suite de ces catastrophes,\nd�couvrirent dans son taudis compl�tement d�compos�e sur le sol. Quand ces citoyens voulurent s'approcher de\nlui afin de le transporter et l'incin�rer, le putride se r�veilla. Il s'agissait du premier zombie !\n\nCette personne � l'origine humaine semblait touch�e par une forme de rage provoquant la mort d'une grande partie de\nson corps. Le cannibalisme impulsif faisant partie int�grante du zombie, il mange toutes les\npersonnes qu'il peut. Ceci provoqua une terrible �pid�mie qui d�buta dans le taudis de ce premier zombie puisque\nune morsure suffisait � contaminer une personne.\n\nCe terrible virus contamina les survivants de la guerre, laissant encore moins d'�tres humains sur Terre. Les\nderniers survivants sont alors forc�s de piller les anciens vestiges de l'humanit� pour survivre. \n\n\n\n");
	wait_user();
	
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
				printf("\n\nLe nom d'utilisateur doit contenir entre 3 et 16 caract�res.\n\n");
			}
			else if (!isAlphaNumeric)
			{
				printf("\n\nLe nom d'utilisateur ne peut contenir que des caract�res alphanum�rique.\n\n");
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
		
		printf("Bienvenue %s dans Die4laugh !\n\n",username_input.c_str());
		printf("[1] Jouer\n");
		printf("[2] Mon profil\n");
		printf("[3] Tableau des scores\n");
		
		printf("\n> ");
		scanf("%d",&choice);
		fflush(stdin);
		
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
	
	clean();
	printf("Die4laugh est un jeu de survie dans un monde hostile peupl� de zombies.\n\nPour survivre le plus longtemps, explorez le d�sert et fouillez les �tendues d�sertiques pour y trouver\ndes armes, du mat�riel et de la nourriture. A chaque kilom�tre, il est possible de proc�der � des\nfouilles. Ces fouilles vous permettent de d�couvrir des objets que vous pourrez utiliser � votre guise.\n\nPr�t(e) � mourir ?\n\n");
	wait_user();
	
	fstat_get(username_input); // d�marre avec les donn�es du profil (s�curit�)
	display_base();
}


std::string Die4laugh::print_item(int id, int type)
{
	std::string item_name, item_desc, item_type, item_prob, item_heavy;
	item_heavy = "no";
	nb_items = 116;
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
			item_desc = "Un vieux sac tout graisseux en papier qui doit bien contenir quelque chose � manger...\nNotez qu'il sent mauvais.";
			item_type = "2"; // container
			item_prob = "50";
			break;
		case 2:
			item_name = "Affaires de citoyen";
			item_desc = "C'est le petit container standard donn� � tout citoyen dans les anciennes communaut�s.\nUn peu comme une pochette surprise.";
			item_type = "2";
			item_prob = "0";
			break;
		case 3:
			item_name = "Ration d'eau";
			item_desc = "La gourde vous permet de vous d�salt�rer. L'eau permet de r�cup�rer son �nergie et d'�tancher la soif\n(pas de limitation par jour).";
			item_type = "1"; // ration d'eau
			item_prob = "0";
			break;
		case 4:
			item_name = "Ailerons de poulet entam�s";
			item_desc = "Deux ailerons de poulet que quelqu'un a d�ja commenc� � manger avant de les jeter ... Hmmm ...";
			item_type = "3"; // bouffe
			item_prob = "40";
			break;
		case 5:
			item_name = "Biscuit fades";
			item_desc = "Une tartelette qui sent vraiment fort... Pensez � quelque chose d'agr�able pendant que vous l'avalerez.";
			item_type = "3";
			item_prob = "40";
			break;
		case 6:
			item_name = "Chewing-gums s�ch�s";
			item_desc = "Une pleine poign�e de chewing-gums tout s�ch�s. En th�orie, �a se m�che, mais �a ne s'avale pas.\nSeulement, dans cet enfer, vous n'�tes pas en position de faire le ou la difficile...";
			item_type = "3";
			item_prob = "40";
			break;
		case 7:
			item_name = "Jambon-beurre moisi";
			item_desc = "Un reste de casse-croute qui n'a d'app�tissant que son souvenir...";
			item_type = "3";
			item_prob = "40";
			break;
		case 8:
			item_name = "Nouilles chinoises";
			item_desc = "Malgr� les ann�es pass�es dans le d�sert, ces nouilles chinoises ont toujours le m�me gout et le\nm�me aspect.";
			item_type = "3";
			item_prob = "40";
			break;
		case 9:
			item_name = "Napolitains moisis";
			item_desc = "Une p�tisserie sous plastique : chocolat-vanille. Si vous agitez l'emballage, vous avez\nl'impression que quelque chose s'est liqu�fi� l�-dedans...";
			item_type = "3";
			item_prob = "40";
			break;
		case 10:
			item_name = "Paquet de chips molles";
			item_desc = "Les chips de ce paquet sont molles et ont un go�t de papier s�ch�, mais on ne va pas faire\nle difficile... Un repas est un repas.";
			item_type = "3";
			item_prob = "40";
			break;
		case 11:
			item_name = "Petit-beurres rances";
			item_desc = "C'est sec et �a a un aspect rassi. Vous donneriez n'importe quoi pour faire passer le gout\nde ces biscuits...";
			item_type = "3";
			item_prob = "40";
			break;
		case 12:
			item_name = "Pims p�rim�s";
			item_desc = "Une poign�e de biscuits fourr�s � la confiture de ... en fait vous l'ignorez... Peut-�tre un\nfruit. Mais �a a un gout de viande maintenant.";
			item_type = "3";
			item_prob = "40";
			break;
		case 13:
			item_name = "Lampe de chevet �teinte";
			item_desc = "C'est une jolie lampe de chevet, mais elle ne fonctionnera pas sans une pile neuve...";
			item_type = "4"; // 4 = assemblage
			item_prob = "40";
			break;
		case 14:
			item_name = "Lampe de chevet allum�e";
			item_desc = "Avec une lampe de chevet, vous aurez moins peur la nuit et vous dormirez peut-�tre mieux ainsi.";
			item_type = "5"; // 5 = bonus d'energie au reveil
			item_prob = "0";
			break;
		case 15:
			item_name = "Pile";
			item_desc = "La pile sert � plein de truc. Mais �a se d�charge souvent trop vite...";
			item_type = "6"; // rien
			item_prob = "75";
			break;
		case 16:
			item_name = "Produits pharmaceutiques";
			item_desc = "Un petit flacon et des produits myst�rieux emball�s sous plastique. Aucune id�e de ce � quoi �a\npeut bien servir... Peut �tre qu'en le m�langeant avec un autre produit ?";
			item_type = "4";
			item_prob = "80";
			break;
		case 17:
			item_name = "Radio K7 �teint";
			item_desc = "Un ancien transistor avec une cassette de blues dedans. La radio elle-m�me est inutile car on ne\ncapte plus rien de nos jours.. Mais avoir un peu de musique chez soi pour couvrir les bruits terrifiants\nde la nuit est toujours r�confortant.";
			item_type = "4";
			item_prob = "50";
			break;
		case 18:
			item_name = "Radio K7 allum�";
			item_desc = "Un ancien transistor avec une cassette de blues dedans. La radio elle-m�me est inutile car on ne\ncapte plus rien de nos jours.. Mais avoir un peu de musique chez soi pour couvrir les bruits terrifiants\nde la nuit est toujours r�confortant.";
			item_type = "7"; // ajout de zombie au r�veil
			item_prob = "0";
			break;
		case 19:
			item_name = "Bo�te d'allumettes";
			item_desc = "Comme dit le dicton : on ne peut pas faire de feu de tout bois. Fa�tes le mentir...";
			item_type = "4";
			item_prob = "55";
			break;
		case 20:
			item_name = "St�ro�des Anabolisants";
			item_desc = "Cette drogue est id�ale pour vous faire voir la vie en rose : plus de fatigue au prix de seulement\nquelques convulsions et d'un peu de bave aux l�vres... Gare � l'accoutumance !";
			item_type = "8"; // drugs1
			item_prob = "35";
			break;
		case 21:
			item_name = "Cutter";
			item_desc = "Ce petit couteau � lame r�tractable disponible en coloris mauve ou fushia s'accordera tr�s bien avec\nla couleur des visc�res de vos ennemis. Pour peu qu'il traverse.";
			item_type = "9"; // weapon
			item_prob = "45";
			break;	
		case 22:
			item_name = "Cutter (cass�)";
			item_desc = "Ce petit couteau � lame r�tractable disponible en coloris mauve ou fushia s'accordera tr�s bien avec\nla couleur des visc�res de vos ennemis. Pour peu qu'il traverse.";
			item_type = "10"; // broken weapon
			item_prob = "5";
			break;
		case 23:
			item_name = "Canif d�risoire";
			item_desc = "\"Canif [n.m.] : petit couteau de poche dont la lame se replie.\"Son porteur se replie aussi g�n�ralement s'il est intelligent.";
			item_type = "9"; // weapon
			item_prob = "45";
			break;	
		case 24:
			item_name = "Canif d�risoire (cass�)";
			item_desc = "\"Canif [n.m.] : petit couteau de poche dont la lame se replie.\"Son porteur se replie aussi g�n�ralement s'il est intelligent.";
			item_type = "10"; // broken weapon
			item_prob = "5";
			break;		
		case 25:
			item_name = "Jerrycan";
			item_desc = "Le Jerrycan contient plusieurs rations d'eau non-potable. Toutefois, il y a peut-�tre une fa�on de les purifier...";
			item_type = "6";
			item_prob = "45";
			break;
		case 26:
			item_name = "Micropur effervescent";
			item_desc = "Une capsule de produit d�sinfectant � mettre dans de l'eau pour la nettoyer. Avant, c'�tait utilis� pour r�curer les toilettes. Vous imaginez ais�ment le go�t de l'eau apr�s... (ATTENTION: Le rendement de\nce produit est faible en comparaison d'un Purificateur industriel)";
			item_type = "4";
			item_prob = "45";
			break;
		case 27:
			item_name = "Clef � Molette";
			item_desc = "Avec une cl� � Molette, vous pouvez au choix bricoler un objet ou d�truire quelque chose. Pas forcement un objet d'ailleurs...";
			item_type = "9";
			item_prob = "25";
			break;
		case 28:
			item_name = "Clef � Molette (cass�)";
			item_desc = "Avec une cl� � Molette, vous pouvez au choix bricoler un objet ou d�truire quelque chose. Pas forcement un objet d'ailleurs...";
			item_type = "10";
			item_prob = "0";
			break;
		case 29:
			item_name = "Grosse cha�ne rouill�e";
			item_desc = "Cette vieille cha�ne en fer est compl�tement distordue et n'a plus grande utilit�... Mais on doit bien pouvoir �trangler quelqu'un avec.";
			item_type = "9";
			item_prob = "25";
			break;
		case 30:
			item_name = "Grosse cha�ne rouill�e (cass�)";
			item_desc = "Cette vieille cha�ne en fer est compl�tement distordue et n'a plus grande utilit�... Mais on doit bien pouvoir �trangler quelqu'un avec.";
			item_type = "10";
			item_prob = "25";
			break;
		case 31:
			item_name = "Machette";
			item_desc = "Au d�part on se frayait un chemin avec. Ici aussi c'est le cas, mais la v�g�tation est tr�s vindicative et sinistrement bruyante...";
			item_type = "9";
			item_prob = "5";
			break;
		case 32:
			item_name = "Machette (cass�)";
			item_desc = "Au d�part on se frayait un chemin avec. Ici aussi c'est le cas, mais la v�g�tation est tr�s vindicative et sinistrement bruyante...";
			item_type = "10";
			item_prob = "1";
			break;
		case 33:
			item_name = "D�bris m�talliques";
			item_desc = "Des bouts de ferrailles rouill�es, du grillage, des vis...";
			item_type = "6";
			item_prob = "10";
			break;
		case 34:
			item_name = "Souche de bois pourrie";
			item_desc = "Une grosse souche de bois couverte de champignons visqueux.";
			item_type = "6";
			item_prob = "10";
			break;
		case 35:
			item_name = "Planche tordue";
			item_desc = "Une planche de bois compl�tement moisie mais encore � peu pr�s solide...";
			item_type = "6";
			item_prob = "100";
			break;
		case 36:
			item_name = "Ferraille";
			item_desc = "Du m�tal... Un peu lourd, mais �a sert toujours !";
			item_type = "6";
			item_prob = "100";
			break;
		case 37:
			item_name = "Bandage rudimentaire";
			item_desc = "�a sent mauvais, il y a des traces de moisissure, mais franchement, vous n'�tes pas en position de faire votre difficile. Ce bandage permet de panser une blessure.";
			item_type = "11"; // bandage
			item_prob = "10";
			break;
		case 38:
			item_name = "Os charnu";
			item_desc = "Un os avec encore un peu de viande autour... Bizarre. �a a l'air encore frais en plus. Peut-�tre un animal tu� pendant la nuit ?";
			item_type = "3"; // os charnu
			item_prob = "30";
			break;
		case 39:
			item_name = "Os humain f�l�";
			item_desc = "Un os (un tibia sans doute) tout s�ch� que quelqu'un a rong� r�cemment semble-t-il... Ca doit pouvoir encore servir.";
			item_type = "9";
			item_prob = "1";
			break;
		case 40:
			item_name = "Os humain f�l� (cass�)";
			item_desc = "Un os (un tibia sans doute) tout s�ch� que quelqu'un a rong� r�cemment semble-t-il... Ca doit pouvoir encore servir.";
			item_type = "10";
			item_prob = "0";
			break;
		case 41:
			item_name = "Parac�to�de 7mg";
			item_desc = "Un antipyr�tique puissant capable d'enrayer n'importe quelle infection.\nLa notice pr�cise : � ce m�dicament peut parfois provoquer quelques effets secondaire g�nant (acn�, vomissements, convulsions et mort violente) �.";
			item_type = "12"; // paracetoide
			item_prob = "25";
			break;
		case 42:
			item_name = "Structures m�talliques";
			item_desc = "Du m�tal assembl� pour former une structure de soutien.";
			item_type = "6"; 
			item_prob = "10";
			item_heavy = "yes";
			break;
		case 43:
			item_name = "Poutre rafistol�e";
			item_desc = "Un assemblage de bois qui forme une poutre de soutien relativement solide.";
			item_type = "6"; 
			item_prob = "10";
			item_heavy = "yes";
			break;
		case 44:
			item_name = "Buche en bon �tat";
			item_desc = "Une belle buche qui pourrait tout � fait servir de tabouret � la maison. Apr�s tout... C'est mieux que rien.";
			item_type = "6";
			item_prob = "5";
			break;
		case 45:
			item_name = "Composant �lectronique";
			item_desc = "Une vieille plaque probablement sortie d'un poste de radio ou d'un quelconque gadget �lectrique.";
			item_type = "6";
			item_prob = "25";
			break;
		case 46:
			item_name = "Courroie";
			item_desc = "Une courroie... Ca doit s�rement servir � quelque chose.";
			item_type = "6";
			item_prob = "20";
			break;
		case 47:
			item_name = "Explosifs bruts";
			item_desc = "Boum !";
			item_type = "17"; // explosifs
			item_prob = "0";
			break;
		case 48:
			item_name = "D�tonateur compact";
			item_desc = "Un dispositif compact qui peut faire exploser une petite charge d'explosif...";
			item_type = "6";
			item_prob = "25";
			break;
		case 49:
			item_name = "Fragments de t�le";
			item_desc = "Des morceaux de t�le qui ne demandent qu'� servir de protection dans votre maison...\nPour peu que vous les assembliez correctement.";
			item_type = "6";
			item_prob = "25";
			item_heavy = "yes";
			break;
		case 50:
			item_name = "Poign�e de vis et �crous";
			item_desc = "Certaines pi�ces sont rouill�es, d'autres sont couvertes de mousse verd�tre,\nmais elles ont toutes au moins le m�rite de continuer � remplir leur r�le. Plus ou moins.";
			item_type = "6";
			item_prob = "25";
			break;
		case 51:
			item_name = "Rustine";
			item_desc = "Toujours pratique pour coller des choses ensemble.";
			item_type = "6";
			item_prob = "75";
			break;
		case 52:
			item_name = "Tube de cuivre";
			item_desc = "Un tube en cuivre, un peu sale et dont l'utilit� vous �chappe...";
			item_type = "6";
			item_prob = "60";
			break;
		case 53:
			item_name = "Sac de ciment";
			item_desc = "Un gros sac de ciment de qualit� tr�s moyenne...\nUne fois dilu� dans de l'eau, �a s�che rapidement pour donner du b�ton particuli�rement r�sistant !";
			item_type = "4";
			item_prob = "50";
			item_heavy = "yes";
			break;
		case 54:
			item_name = "Moteur incomplet";
			item_desc = "C'est un genre de petit moteur plein de traces d'huile brul�e et mati�res calcin�es ind�finissables. Par contre, il p�se son poids et il semble lui manquer pas mal de pi�ces...";
			item_type = "4";
			item_prob = "5";
			item_heavy = "yes";
			break;
		case 55:
			item_name = "Poudre Super-Fuzz";
			item_desc = "Selon le �poques, cette poudre a tour � tour servi de d�tonateur pour divers pi�ces d'artillerie, puis comme\ndrogue bas de gamme pour citoyen en manque avant d'�tre utilis�e comme ingr�dient principal dans les feux d'artifice.\nDans les 3 cas, beaucoup de gens n'y ont pas surv�cu.";
			item_type = "6";
			item_prob = "10";
			break;
		case 56:
			item_name = "Tube de lancement Floush";
			item_desc = "Plusieurs longs tubes en plastique sans grand int�r�t.";
			item_type = "6";
			item_prob = "10";
			item_heavy = "yes";
			break;
		case 57:
			item_name = "Lentille convexe";
			item_desc = "Cette lentille en bon �tat n'attend qu'un peu de votre ing�niosit� pour �tre utilis� efficacement.";
			item_type = "6";
			item_prob = "25";
			break;
		case 58:
			item_name = "Diode Lazer";
			item_desc = "Un composant �lectronique d'une �poque r�volue, dans l'�tat on peut s'en servir de juda, m�me si on ne voit pas � travers.";
			item_type = "6";
			item_prob = "25";
			break;
		case 59:
			item_name = "Sachet d'herbe fra�che";
			item_desc = "Puisqu'on vous dit que c'est de l'herbe banale, il y a surement une autre utilit� � cette herbe qu'une simple cigarette roul�e.";
			item_type = "6";
			item_prob = "20";
			break;
		case 60:
			item_name = "Bidon d'huile vide";
			item_desc = "On trouve de temps en temps des bidons d'huile vides dans le d�sert, souvent accompagn� d'un cadavre.\nQuand est ce que les citoyens comprendront que l'huile, �a ne se boit pas ...";
			item_type = "6";
			item_prob = "25";
			break;
		case 61:
			item_name = "Morceau de caisse";
			item_desc = "Un vieil assemblage de planches qui �tait utilis� pour fermer une grosse caisse, autrefois.\nCa pourrait bien servir de d�fense, si seulement vous trouviez de quoi le consolider.";
			item_type = "4";
			item_prob = "50";
			item_heavy = "yes";
			break;
		case 62:
			item_name = "Pav�s de b�ton informes";
			item_desc = "�a ne ressemble pas le moins du monde � des briques, mais c'est en b�ton arm� et �a doit pouvoir servir de d�fenses chez soi...\nAu pire, jetez-les sur des zombies, �a sera un peu comme une manifestation.";
			item_type = "13";
			item_prob = "5";
			item_heavy = "yes";
			break;
		case 63:
			item_name = "Plaque de bois solide";
			item_desc = "Ce gros couvercle de caisse fera bien l'affaire pour bloquer une br�che du campement.";
			item_type = "13";
			item_prob = "5";
			item_heavy = "yes";
			break;
		case 64:
			item_name = "Plaque de t�le";
			item_desc = "Rien ne vaut une plaque de t�le rouill�e pour emp�cher les zombies de vous atteindre...";
			item_type = "13";
			item_prob = "5";
			item_heavy = "yes";
			break;
		case 65:
			item_name = "Table J�rpen";
			item_desc = "Enti�rement assembl�e avec des �lastiques et des picots de bois, cette table fera s�rement tr�s joli dans votre �salon�.\nEt mise � la verticale, elle pourrait bien aussi vous sauver la vie, un soir.";
			item_type = "13";
			item_prob = "10";
			item_heavy = "yes";
			break;
		case 66:
			item_name = "Tr�teau";
			item_desc = "Un tr�teau relativement solide qui devrait s'av�rer utile pour consolider les d�fenses du campement.";
			item_type = "13";
			item_prob = "45";
			item_heavy = "yes";
			break;
		case 67:
			item_name = "Vieille porte";
			item_desc = "C'est une porte en bois. Mod�le classique, autrefois blanche, mais couverte de terre aujourd'hui. �a pourra toujours servir...";
			item_type = "13";
			item_prob = "45";
			item_heavy = "yes";
			break;
		case 68:
			item_name = "Torche";
			item_desc = "Elle doit bien br�ler quelques heures... �a sera toujours �a de plus pour �loigner les zombies.";
			item_type = "13";
			item_prob = "0";
			break;
		case 69:
			item_name = "Torche consum�e";
			item_desc = "Un vieux bout de bois calcin� qui ne vous servira s�rement plus � grand chose...";
			item_type = "9";
			item_prob = "0";
			break;	
		case 70:
			item_name = "Torche consum�e (cass�)";
			item_desc = "Un vieux bout de bois calcin� qui ne vous servira s�rement plus � grand chose...";
			item_type = "10";
			item_prob = "0";
			break;
		case 71:
			item_name = "Tournevis";
			item_desc = "Le tournevis visse et d�visse, il vous permet de r�parer des choses et � la limite, d'ouvrir des bo�tes de conserve. En dernier ressort, plantez-le dans une t�te: �a pourrait bien vous sauver la vie...";
			item_type = "9";
			item_prob = "40";
			break;
		case 72:
			item_name = "Tournevis (cass�)";
			item_desc = "Le tournevis visse et d�visse, il vous permet de r�parer des choses et � la limite, d'ouvrir des bo�tes de conserve. En dernier ressort, plantez-le dans une t�te: �a pourrait bien vous sauver la vie...";
			item_type = "9";
			item_prob = "1";
			break;
		case 73:
			item_name = "Meuble en kit";
			item_desc = "Un meuble en pi�ces d�tach�es, difficile � identifier...";
			item_type = "6";
			item_prob = "60";
			item_heavy = "yes";
			break;
		case 74:
			item_name = "Viande ind�finissable";
			item_desc = "Vous �tes quasiment certain que cette chose molle et visqueuse peut se manger. En tous cas, �a ne sent pas mauvais et �a ne bouge pas.";
			item_type = "3";
			item_prob = "30";
			break;
		case 75:
			item_name = "Viande humaine";
			item_desc = "Allez on oublie ce qu'on vient de manger et on passe � autre chose.";
			item_type = "3";
			item_prob = "20";
			break;
		case 76:
			item_name = "Porti�re de voiture incompl�te";
			item_desc = "Cette grosse porti�re fera parfaitement office de bouclier improvis� dans le d�sert,\nquand il s'agira de passer en force dans des hordes de cadavres avides de votre d�licieux cerveau.";
			item_type = "4";
			item_prob = "5";
			item_heavy = "yes";
			break;
		case 77:
			item_name = "Porti�re de voiture";
			item_desc = "Cette grosse porti�re fera parfaitement office de bouclier improvis� dans le d�sert,\nquand il s'agira de passer en force dans des hordes de cadavres avides de votre d�licieux cerveau.";
			item_type = "13";
			item_prob = "1";
			item_heavy = "yes";
			break;
		case 78:
			item_name = "Moteur";
			item_desc = "C'est un genre de petit moteur plein de traces d'huile brul�e et mati�res calcin�es ind�finissables. Par contre, il p�se son poids et il semble lui manquer pas mal de pi�ces...";
			item_type = "6";
			item_prob = "0";
			item_heavy = "yes";
			break;
		case 79:
			item_name = "Sac suppl�mentaire";
			item_desc = "Id�al pour vos randonn�es entre amis, il vous permet de stocker plus de souvenirs: biologiques, nucl�aires ou autres.";
			item_type = "14"; // slot supplementaire
			item_prob = "12";
			break;
		case 80:
			item_name = "Ceinture � poches";
			item_desc = "Cette ceinture vous permet de disposer d'1 emplacement de sac � dos suppl�mentaire.";
			item_type = "14";
			item_prob = "4";
			break;
		case 81:
			item_name = "Sac super-pratique";
			item_desc = "Le compagnon de voyage id�al ! Poche lat�rale, �tanche, renforc� aux �paules, auto-massant pendant la marche\net avec un joli logo �Desert Addict� chrom�.";
			item_type = "14";
			item_prob = "0";
			break;
		case 82:
			item_name = "Caddie";
			item_desc = "On l'appelle �Le Caddie�. Personne ne sait � quoi �a pouvait bien servir � part mettre des objets dedans,\nmais le nom inscrit dessus �tait rigolo. Bon, par contre, �a ne roule pas bien dans le sable.";
			item_type = "14";
			item_prob = "0";
			break;
		case 83:
			item_name = "Caddie bancal";
			item_desc = "Un genre de gros chariot m�tallique, mais l'un des essieux est manquant. Il faudrait quelque chose pour le remplacer...";
			item_type = "4";
			item_prob = "15";
			item_heavy = "yes";
			break;
		case 84:
			item_name = "Bobine de fil de fer";
			item_desc = "Attention � ne pas s�emm�ler avec, on ne voudrait pas avoir � vous couper les doigts pour vous en lib�rer.";
			item_type = "4";
			item_prob = "25";
			break;
		case 85:
			item_name = "Mine Antipersonnelle";
			item_desc = "On trouve encore des mines dans le d�sert, en g�n�ral, ce sont plus les gens imprudents que les zombies qui marchent dessus.";
			item_type = "15"; // mine
			item_prob = "1";
			break;	
		case 86:
			item_name = "Cyanure";
			item_desc = "Quand rien ne va, une petite capsule de cyanure, un grand verre d�eau et on attend que �a passe avec un sourire apais�.";
			item_type = "16"; // cyanure
			item_prob = "25";
			break;	
		case 87:
			item_name = "Fusil d'assaut";
			item_desc = "Une version modifi�e du AK-47, plus compacte, probablement destin� � un usage \"civil\"... La chasse � la Galinette Cendr�e diront certains.";
			item_type = "4";
			item_prob = "0";
			break;	
		case 88:
			item_name = "Revolver";
			item_desc = "Une arme de poing : le mod�le P-22, tr�s r�put� pour sa fiabilit� et sa grande pr�cision. Mais �a ne sert strictement � rien sans munition...";
			item_type = "4";
			item_prob = "20";
			break;
		case 89:
			item_name = "Appareil �lectronique en panne";
			item_desc = "Un vieil appareil �lectro-m�nager impossible � identifier. Peut-�tre qu'en le d�montant vous pourriez obtenir quelque chose ? ";
			item_type = "6";
			item_prob = "40";
			break;
		case 90:
			item_name = "Matelas";
			item_desc = "ZZzzzz... Grincement... ZZzzzz... Grincement...";
			item_type = "13";
			item_prob = "40";
			item_heavy = "yes";
			break;
		case 91:
			item_name = "M�dicament sans �tiquette";
			item_desc = "Une bo�te de m�dicaments dont l'�tiquette est compl�tement effac�e.\nLes cachets dedans sont pour la plupart moisis, mais vous en trouver quelques uns qui soient encore �consommables�.\nMais �tes-vous suffisamment mal pour pouvoir avaler �a ?";
			item_type = "18"; // mse
			item_prob = "40";
			break;
		case 92:
			item_name = "Piqure de calmant";
			item_desc = "Allez calmez-vous... Vous en verrez bien d'autres.";
			item_type = "19"; // piqure
			item_prob = "25";
			break;
		case 93:
			item_name = "Hydratone";
			item_desc = "Pratique, l'Hydratone tient dans la poche et peut �tancher votre soif quelques minutes apr�s l'ingestion.\nToutefois, elle ne retire PAS les effets de la fatigue et ne r�g�n�re PAS l'�nergie.";
			item_type = "20"; // hydratone
			item_prob = "25";
			break;
		case 94:
			item_name = "Betapropine 5mg p�rim�e";
			item_desc = "Ce petit cachet a un effet pour le moins myst�rieux... Sur la bo�te, il est �crit:\n\"ne pas donner � un testeur de moins de 18 ans\". �trange.";
			item_type = "18";
			item_prob = "20";
			break;
		case 95:
			item_name = "Twino�de 500mg";
			item_desc = "Un concentr� de caf��ne, de th�ine, de diverses drogues chimiques et de testicules de taureau broy�es.\nLa drogue id�ale pour les coups de fouets en fin de journ�e, ou quand il s'agit de fuir face � une horde de zombies qui en veulent � votre foie.";
			item_type = "21"; // twinoid
			item_prob = "20";
			break;
		case 96:
			item_name = "Poign�e de cartouches";
			item_desc = "La cl� d'acc�s pour des armes de qualit�.";
			item_type = "6";
			item_prob = "0";
			break;
		case 98:
			item_name = "Vodka Marinostov";
			item_desc = "Un coup de fouet tr�s violent pour oublier la fatigue (et r�cup�rer toute son �nergie)... 85� d'alcool pur, avec diverses choses vaguement organiques qui flottent dedans. Sant� camarade !";
			item_type = "22"; // alcool
			item_prob = "20";
			break;
		case 99:
			item_name = "Whisky Koehr";
			item_desc = "Un cocktail invent� par un certain Teddy si on en croit l'�tiquette. M�lange de rhum, de piment rouge et de whiskey, avec un doigt marin� qui flotte entre deux eaux...";
			item_type = "22";
			item_prob = "5";
			break;
		case 100:
			item_name = "Melon d'intestin";
			item_desc = "Habituellement le melon d'intestin pousse dans le ventre des cadavres, au niveau du gros colon. Il semblerait pourtant que votre potager en ait donn� de tr�s jolis... Peut �tre avez vous cultiv� sur un vieux cimeti�re indien ?";
			item_type = "3";
			item_prob = "0";
			break;
		case 101:
			item_name = "L�gume suspect";
			item_desc = "Un genre de... l�gume... Difficile � dire ce qui a essay� de pousser comme �a, mais le principal c'est que �a semble comestible. Ou pas.";
			item_type = "3";
			item_prob = "0";
			break;
		case 102:
			item_name = "Steak app�tissant";
			item_desc = "C'est un peu �lastique et �a sent m�me le poisson... On se demande bien ce que �a peut �tre,\nmais c'est surement plein de vitamines (et pas d'autres choses, esp�rez-vous).";
			item_type = "3";
			item_prob = "20";
			break;
		case 103:
			item_name = "Nouilles chinoises �pic�es";
			item_desc = "Des nouilles copieusement assaisonn�es ! Hmm, �a va vous changer de vos repas � base de chose en d�composition.";
			item_type = "3";
			item_prob = "1";
			break;
		case 104:
			item_name = "Poign�e de bonbons";
			item_desc = "Vous avez une petite larme � l'oeil en contemplant cette poign�e de d�licieux bonbons...";
			item_type = "3";
			item_prob = "1";
			break;
		case 105:
			item_name = "Bon plat fait-maison";
			item_desc = "En apparence, �a n'est gu�re mieux qu'une ration quotidienne. Mais en r�alit� �a a tr�s bon go�t et �a nourrit bien.";
			item_type = "3";
			item_prob = "0";
			break;
		case 106:
			item_name = "Chamallows calcin�s";
			item_desc = "Quelques chamallows tout durcis et qui sentent le rat mort. Maintenant qu'ils sont compl�tement calcin�s, on Peut dire qu'ils sont mangeables.\nOn Peut m�me dire qu'ils sont app�tissants, quand on y r�fl�chit bien...";
			item_type = "3";
			item_prob = "0";
			break;
		case 107:
			item_name = "Epices fortes";
			item_desc = "Un petit sachet d'�pices...";
			item_type = "4";
			item_prob = "20";
			break;
		case 108: 
			item_name = "Tron�onneuse incompl�te";
			item_desc = "Un outil hautement amusant, mais il semblerait qu'il manque une courroie et quelques babioles pour qu'elle fonctionne...";
			item_type = "4";
			item_prob = "0";
			item_heavy = "yes";
			break;
		case 109:
			item_name = "Chamallows s�ch�s";
			item_desc = "Quelques chamallows tout durcis et qui sentent le rat mort. C'est compl�tement immangeable tel quel...";
			item_type = "4";
			item_prob = "5";
			break;
		case 110:
			item_name = "Bo�te-d�jeuner";
			item_desc = "A d�faut d'un vrai repas autour d'une table, avec des couverts et des amis, vous avez cette boite-d�jeuner sp�cial Apocalypse...";
			item_type = "2";
			item_prob = "5";
			break;
		case 111:
			item_name = "Caisse de nourriture";
			item_desc = "Une odeur abominable de moisi et de charogne �mane de cette caisse... Mais vous �tes presque s�r(e) qu'elle contient un petit quelque chose de comestible.\nDu moins vous esp�rez.";
			item_type = "2";
			item_prob = "10";
			item_heavy = "yes";
			break;
		case 112:
			item_name = "Caisse de mat�riel";
			item_desc = "Cette vieille caisse en bois doit contenir des babioles utiles.";
			item_type = "2";
			item_prob = "20";
			item_heavy = "yes";
			break;
		case 113:
			item_name = "Bo�te en m�tal";
			item_desc = "Une vieille bo�te m�tallique couverte de rouille et compl�tement caboss�e. Qui sait ce qu'elle peut bien contenir ?";
			item_type = "2";
			item_prob = "10";
			item_heavy = "yes";
			break;
		case 114:
			item_name = "Gros coffre en m�tal";
			item_desc = "C'est particuli�rement lourd et �a contient s�rement quelque chose de pr�cieux ... Reste � trouver un endroit pour l'ouvrir.";
			item_type = "6";
			item_prob = "3";
			item_heavy = "yes";
			break;
		case 115:
			item_name = "Tron�onneuse �teinte";
			item_desc = "Avec �a, vous allez faire un vrai massacre. Mais sachez qu'on en ressort peut-�tre victorieux mais pas tout � fait indemne...\nCette machine infernale a �t� modifi�e et fonctionne (chose incroyable) avec une simple pile !";
			item_type = "4";
			item_prob = "0";
			item_heavy = "yes";
			break;
		case 116:
			item_name = "Tron�onneuse";
			item_desc = "Avec �a, vous allez faire un vrai massacre. Mais sachez qu'on en ressort peut-�tre victorieux mais pas tout � fait indemne...\nCette machine infernale a �t� modifi�e et fonctionne (chose incroyable) avec une simple pile !";
			item_type = "23";
			item_prob = "0";
			item_heavy = "yes";
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
		printf("   Fatigu�(e)");
	}
	if (no_drugs == true)
	{
		printf("   Clair(e)");
	}
	if (water_day == true)
	{
		printf("   D�salt�r�(e)");
	}
	if (food_day == true)
	{
		printf("   Rassasi�(e)");
	}
	if (drug_day == true)
	{
		printf("   Drogu�(e)");
	}
	if (dependant == true)
	{
		printf("   D�pendant(e)");
	}
	if (thirst == true)
	{
		printf("   Soif");
	}
	if (big_thirst == 1)
	{
		printf("   D�sydrath�(e)");
	}
	if (injury == true)
	{
		printf("   Bl�ss�(e)");
	}
	if (ill == true)
	{
		printf("   Infect�(e)");
	}
	if (meds == true)
	{
		printf("   Immunis�(e)");
	}
	if (alcohol == true)
	{
		printf("   Ivre");
	}
	if (hangover == true)
	{
		printf("   Gueule de bois");
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


void Die4laugh::display_ground()
{
	int i;
	bool empty = true;
	if (ground[0] == 0)
	{
		printf(" Pas d'objets au sol.\n");
	}
	else
	{
		for (i=0; i<ground_size && ground[i] != 0; i++)
		{
			if (print_item(ground[i],2).compare("13") == 0 && location.compare("Campement") == 0) // afficher def +5
				printf("[%d] - %s (+5 def)\n",i+bag_size+1,print_item(ground[i],0).c_str());
			else
				printf("[%d] - %s\n",i+bag_size+1,print_item(ground[i],0).c_str());
		}
	}
}


void Die4laugh::reload_location()
{
	int number, location_alea;

	number = rand()%5;
	if (number != 0) // 4 chance sur 5
	{
		location = "D�sert...";
		monsters = (rand()%10 + days*3)/5;
	}
	else if (kilometers_exhausted[kilometers] >= 4) // si zone �puis�
	{
		location = "D�sert (zone �puis�)";
		monsters = (rand()%10 + days*3)/5;
	}
	else
	{
		nb_locations = 20;
		location_alea = rand()%nb_locations+1;
		monsters = (rand()%10 + rand()%10 - rand()%8 + days*3)/5;
		
		switch(location_alea)
		{
			case 1:
				location = "Petite maison";
				break;
			case 2:
				location = "Puits abandonn�";
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
				location = "Carri�re effondr�e";
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
				location = "Chantiers � l'abandon";
				break;
			case 12:
				location = "Meubles KIELA";
				break;
			case 13:
				location = "Route barr�e";
				break;
		}
	}
	if (monsters < 0) monsters = 0;
	stuck_f(); // etre coinc� par les zombies ou pas
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
			printf("Vous avez d�j� bu une fois aujourd'hui : la seule utilit� de l'eau pour cette journ�e sera\nd'�tancher votre soif plus tard.");
		}
		else
		{
			if (energy >= energy_max && thirst == false && big_thirst == false)
			{
				printf("Vous n'avez pas besoin de boire pour le moment: vous n'�tes pas fatigu�(e) et vous disposez de toute\nvotre �nergie.");
			}
			else
			{
				printf("Vous avalez d'une traite votre ration d'eau... �a fait du bien !");
				if (water_day == true)
				{
				 printf("\n\nCependant vous ne r�cup�rer pas votre �nergie, vous avez d�j� bu aujourd'hui.");
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
					printf("\n\nIl semblerait que vous aviez tellement soif que vous ne r�cup�rez pas d'en�rgie !");
					big_thirst = false;
					thirst = true;
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
		for (i=0; i<bag_size; i++) if (print_item(bag[item],2).compare("14") == 0) do_you_have_weapon = true;
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
			printf("Vous avez ouvert %s, vous trouvez %s � l'int�rieur.",print_item(bag[item],0).c_str(),print_item(final_item,0).c_str());
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
				printf("Vous n'avez pas besoin de manger pour le moment: vous n'�tes pas fatigu�(e) et vous disposez de toute votre �nergie.\n");
			}
			else
			{
				food_day = true;
				if (bag[item] == 38 && meds == false && ill == false && rand()%2 == 0) // os charnu
				{
					printf("\nVous commencez � avoir mal au ventre...\n");
					ill = true;
					bag[item] = 39;
				}
				else if (bag[item] == 102 || bag[item] == 103 || bag[item] == 104 || bag[item] == 105 || bag[item] == 106)
				{
					printf("Une fois n'est pas coutume, vous vous fa�tes plaisir en avalant %s. Ca change des rations quotidiennes infectes...\nVous reprenez du poil de la b�te.",print_item(item,0).c_str());
					energy = energy_max+1;
					sort_empty_racism(bag,bag_size);
					bag[item] = 0;
				}
				else
				{
					printf("Ca a un go�t vraiment bizarre, difficile � d�finir. Mais �a remplit son r�le : remplir votre estomac...\n");
					energy = energy_max;
					sort_empty_racism(bag,bag_size);
					bag[item] = 0;
				}
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
		 	 printf("Vous avez fabriqu� %s en combinant %s et %s.",print_item(14,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
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
		 	 printf("Vous avez fabriqu� %s en combinant %s et %s.",print_item(bag[item],0).c_str(),print_item(16,0).c_str(),print_item(16,0).c_str());
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
				printf("Vous avez fabriqu� %s en combinant %s et %s.",print_item(18,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
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
		 	 printf("Vous avez fabriqu� %s en combinant %s et %s.",print_item(3,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
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
		 	 printf("Vous avez fabriqu� %s en combinant %s et %s.",print_item(62,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
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
		 	 printf("Vous avez fabriqu� %s en combinant %s et %s.",print_item(63,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
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
		 	 printf("Vous avez fabriqu� %s en combinant %s et %s.",print_item(68,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
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
		 	 printf("Vous avez fabriqu� %s en combinant %s, %s, %s et %s.",print_item(77,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str(),print_item(bag[need_item2],0).c_str(),print_item(bag[need_item3],0).c_str());
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
		 	 printf("Vous avez fabriqu� %s en combinant %s, %s, %s, %s, %s et %s.",print_item(78,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str(),print_item(bag[need_item2],0).c_str(),print_item(bag[need_item3],0).c_str(),print_item(bag[need_item4],0).c_str(),print_item(bag[need_item5],0).c_str());
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
		 	 printf("Vous avez fabriqu� %s en combinant %s, %s, %s et %s.",print_item(82,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str(),print_item(bag[need_item2],0).c_str(),print_item(bag[need_item3],0).c_str());
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
		 	 printf("Vous avez fabriqu� %s en combinant %s, %s, %s, %s et %s.",print_item(85,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str(),print_item(bag[need_item2],0).c_str(),print_item(bag[need_item3],0).c_str(),print_item(bag[need_item4],0).c_str());
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
		else if (bag[item] == 87) // revolver
		{
		 need_item = check_bag(96,-1);
		 if (need_item != -1)
		 {
		 	 printf("Vous avez fabriqu� %s en combinant %s et %s.",print_item(87,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
		 	 bag[item] = 87;
			 bag[need_item] = 0;
		 	 sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s.",print_item(96,0).c_str());
		 }
		}
		else if (bag[item] == 88) // fusil d'assaut
		{
		 need_item = check_bag(96,-1);
		 if (need_item != -1)
		 {
		 	 printf("Vous avez fabriqu� %s en combinant %s et %s.",print_item(88,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
		 	 bag[item] = 88;
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
		 if (need_item != -1)
		 {
		 	 printf("Vous avez fabriqu� %s en combinant %s et %s.",print_item(103,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
		 	 bag[item] = 103;
			 bag[need_item] = 0;
		 	 sort_empty_racism(bag,bag_size);
		 }
		 else
		 {
		 	printf("Impossible, vous avez besoin de %s.",print_item(8,0).c_str());
		 }
		}
		else if (bag[item] == 109) // chamallow
		{
			need_item = check_bag(68,-1);
			if (need_item != -1)
			{
				printf("Vous avez fabriqu� %s en combinant %s et %s.",print_item(106,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str());
				bag[item] = 106;
				bag[need_item] = 0;
				sort_empty_racism(bag,bag_size);
			}
			else
			{
			printf("Impossible, vous avez besoin de %s.",print_item(68,0).c_str());
			}
		}
		else if (bag[item] == 108) // tronconneuse incompl�te
		{
			need_item = check_bag(46,-1);
			need_item2 = check_bag(50,-1);
			need_item3 = check_bag(51,-1);
			need_item4 = check_bag(78,-1);
			if (need_item != -1 && need_item2 != -1 && need_item3 != -1 && need_item4 != -1)
			{
				printf("Vous avez fabriqu� %s en combinant %s, %s, %s, %s et %s.",print_item(115,0).c_str(),print_item(bag[item],0).c_str(),print_item(bag[need_item],0).c_str(),print_item(bag[need_item2],0).c_str(),print_item(bag[need_item3],0).c_str(),print_item(bag[need_item4],0).c_str());
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
		else if (bag[item] == 115) // tronconneuse �teinte
		{
			need_item = check_bag(15,-1);
			if (need_item != -1)
			{
				printf("Vous avez fabriqu� %s en combinant %s et %s.",print_item(116,0).c_str(),print_item(bag[item],115).c_str(),print_item(bag[need_item],15).c_str());
				bag[item] = 116;
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
			printf("Les effets de la drogue ne tardent pas � se faire sentir: naus�e, tremblements, sueurs froides... Mais au moins,\n�a vous donne un bon coup de fouet. N'en abusez pas !");
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
				printf("\n\nMauvaise nouvelle ! Vous devenez par la m�me occasion d�pendant(e) ! Vous devrez dor�navant consommer au\nmoins une drogue par jour ou mourir !");
				dependant = true;
			}
			stat_number_drugs++;
		}
	}
	
	else if (print_item(bag[item],2).compare("9") == 0) // weapons
	{
		int prob_b, prob_k, killnb, broken_item;
		int random_prob;
		
		if (bag[item] == 21) {prob_b = 70; prob_k = 65; killnb=1; broken_item=22;} // cutter
		else if (bag[item] == 23) {prob_b = 35; prob_k = 65; killnb=1; broken_item=24;} // canif d�risoire
		else if (bag[item] == 27) {prob_b = 10; prob_k = 40; killnb=1; broken_item=28;} // cl� a molette
		else if (bag[item] == 29) {prob_b = 20; prob_k = 60; killnb=1; broken_item=30;} // chaine
		else if (bag[item] == 31) {prob_b = 15; prob_k = 75; killnb=2; broken_item=32;} // machette
		else if (bag[item] == 39) {prob_b = 40; prob_k = 70; killnb=1; broken_item=40;} // os felee
		else if (bag[item] == 69) {prob_b = 80; prob_k = 15; killnb=1; broken_item=70;} // torche consum�e
		else if (bag[item] == 71) {prob_b = 80; prob_k = 15; killnb=1; broken_item=72;} // tournevis
		
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
				printf("Vous avez �limin� %d zombies en utilisant %s. Ha ! Ha ! Un peu plus de chair �tal�e... Ca soulage de supprimer du zombie de temps en temps.\n\n",killnb,print_item(22,0).c_str());
				stat_number_kills = stat_number_kills + killnb;
			}
			else
			{
				printf("Vous avez frapp� de toutes vos forces sur le bipode, malheureusement il ne s'est pas �croul� sur vos coups.\n");
			}
			random_prob = rand()%100;
			if (random_prob < prob_b)
			{
				bag[item] = broken_item; // item cass�
				printf("\n\nToutefois : votre arme a �t� cass�e sous le choc.");
			}
		}
	}
	
	else if (print_item(bag[item],2).compare("11") == 0) // bandage
	{
		if (convalescent == true)
		{
			printf("Vous ne pouvez pas appliquer un nouveau bandage, vous �tes d�j� en �tat de convalescence.\n");
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
		printf("Ce m�dicament a renforc� votre organisme : vous ne subirez pas d''infection. Cet effet se dissipera le lendemain.\nNote : cet effet ne prot�ge pas des infections provoqu�es par une blessure non-trait�e");
		 if (drug_day == false)
		 {
		 	drug_day = true;
		 }
		 else
		 {
			printf("\n\nMauvaise nouvelle ! Vous devenez par la m�me occasion d�pendant(e) !\nVous devrez dor�navant consommer au moins une drogue par jour ou mourir !");
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
			printf("Boom ! Vous avez �limin� %d zombies en utilisant %s. Ha ! Ha ! Un peu plus de chair �tal�e... Ca soulage de supprimer du zombie de temps en temps.\n\n",killnb,print_item(22,0).c_str());
			stat_number_kills = stat_number_kills + killnb;
		}
	}

	else if (print_item(bag[item],2).compare("18") == 0) // drugs3
	{
		int rand_number = rand()%4;
		stat_number_drugs++;

		if (rand_number == 0)
		{
			printf("Les effets de la drogue ne tardent pas � se faire sentir: naus�e, tremblements, sueurs froides... Mais au moins,\n�a vous donne un bon coup de fouet. N'en abusez pas !");
			energy = energy_max;
		}
		else if (rand_number == 1)
		{
			printf("Vous regrettez rapidement d'avoir aval� %s...\nCe produit se r�v�le �tre un puissant st�ro�de pour animaux (le genre que l'on donnait aux chevaux de course).\nVous r�cup�rez votre �nergie, mais vous devenez imm�diatement D�pendant(e) aux drogues !",print_item(item,0).c_str());
			energy = energy_max+1;
			dependant = true;
		}
		else if (rand_number == 2)
		{
			printf("Vous gobez %s. Apr�s plusieurs minutes, vous sentez une douleur sourde vous serrer le cr�ne et votre nez se met � saigner.\nRien d'insupportable, mais rien de positif non plus...",print_item(item,0).c_str());
		}
		else if (rand_number == 3)
		{
			printf("Quelques secondes � peine apr�s, c'est la panique... Sueurs froids, sentiment de pers�cution...\nVous vous recroquevillez, le souffle coup�, en esp�rant que �a passe... mais �a ne passe pas...",print_item(item,0).c_str());
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
			printf("\n\nMauvaise nouvelle ! Vous devenez par la m�me occasion d�pendant(e) ! Vous devrez dor�navant consommer au\nmoins une drogue par jour ou mourir !");
			dependant = true;
		}
	}
	
	else if (print_item(bag[item],2).compare("19") == 0) // drugs4
	{
		stat_number_drugs++;
		if (terror == false)
		{
			printf("Vous utilisez %s, mais ce produit ne semble avoir aucun effet imm�diat notable... Peut-�tre n'en aviez vous pas vraiment besoin ?\n",print_item(item,0).c_str());
		}
		else
		{
			printf("La drogue fait rapidement effet... Tout vous semble soudainement plus calme, plus serein...\nM�me les �v�nements atroces des derniers jours vous semblent maintenant sans importance... Ca va mieux.\n");
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
			printf("\n\nMauvaise nouvelle ! Vous devenez par la m�me occasion d�pendant(e) ! Vous devrez dor�navant consommer au\nmoins une drogue par jour ou mourir !");
			dependant = true;
		}
	}
	
	else if (print_item(bag[item],2).compare("20") == 0) // drugs5
	{
		stat_number_drugs++;
		if (thirst == false && big_thirst == false)
		{
			printf("Vous utilisez %s, mais ce produit ne semble avoir aucun effet imm�diat notable... Peut-�tre n'en aviez vous pas vraiment besoin ?\n",print_item(item,0).c_str());
		}
		else
		{
			printf("Vous avalez votre pillule...\nQuelques instants apr�s, la sensation de soif finit par s'estomper...");
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
			printf("\n\nMauvaise nouvelle ! Vous devenez par la m�me occasion d�pendant(e) ! Vous devrez dor�navant consommer au\nmoins une drogue par jour ou mourir !");
			dependant = true;
		}
	}
	
	else if (print_item(bag[item],2).compare("21") == 0) // drugs6
	{
		stat_number_drugs++;
		printf("C'est pas tous les jours qu'on peut avaler de la c�me de qualit�.\nLes effets sont quand m�me l�: naus�e, tremblements, sueurs froides...\nEn bien plus intense que pour une drogue normale (bonus d'�nergie)...\nN'en abusez pas !");
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
			printf("\n\nMauvaise nouvelle ! Vous devenez par la m�me occasion d�pendant(e) ! Vous devrez dor�navant consommer au\nmoins une drogue par jour ou mourir !");
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
				printf("Vous n'avez pas besoin de boire pour le moment: vous n'�tes pas fatigu�(e) et vous disposez de toute votre �nergie.\n");
			}
			else
			{
				stat_number_alcohol++;
				printf("Vous avez la t�te qui tourne, limite envie de vomir, mais au moins �a vous a r�veill�.\n");
				energy = energy_max;
				bag[item] = 0;
				alcohol = true;
				sort_empty_racism(bag,bag_size);
			}
		}
	}

	else if (print_item(bag[item],2).compare("9") == 0) // weapons � recharge
	{
		int prob_b, prob_k, killnb, dump_item;
		int random_prob;
		
		if (bag[item] == 116) {prob_b = 30; prob_k = 95; killnb=3; dump_item=115;} // tron�onneuse

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
				printf("Vous avez �limin� %d zombies en utilisant %s. Ha ! Ha ! Un peu plus de chair �tal�e... Ca soulage de supprimer du zombie de temps en temps.\n\n",killnb,print_item(22,0).c_str());
				stat_number_kills = stat_number_kills + killnb;
			}
			else
			{
				printf("Vous avez manqu� votre coup !\n");
			}
			random_prob = rand()%100;
			if (random_prob < prob_b)
			{
				bag[item] = dump_item; // item d�charg�
				printf("\n\nToutefois :  votre arme est d�charg�e.");
			}
		}
	}

	sort_empty_racism(bag,bag_size); // securit�
	printf("\n\n");
	deep_mode = false;
	wait_user();
}


void Die4laugh::move_item(int number)
{
	int i;
	bool count_bag = false;
	bool you_got_an_extension = false;
	bool you_got_heavy_item = false;
	for (i=0; i<bag_size; i++) if (print_item(bag[i],2).compare("14") != 0 && bag[i] != 0) count_bag = true; // detecte si il y a des items autre que des extensions
	
	if (number > bag_size) // ground to bag
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
					printf("Vous devez d'abord vider l'int�gralit� de votre sac avant de pouvoir d�poser une extension de sac.\n");
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
	if (number > bag_size) // ground to bag
	{
		for (i=0; i<bag_size; i++)
		{
			//printf("bag : %d / !slot : %d / i : %d\n",bag[i],!you_got_an_extension,i);
			if (bag[i] == 0 && !you_got_an_extension) // trouve un emplacement vide si l'objet n'est pas une extension lorsqu'on en a deja une
			{
				if (you_got_heavy_item)
				{
					clean();
					printf("Vous portez d�j� un objet encombrant.\n");
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
			printf("L'objet a �t� ajout� � votre sac.\n\n");
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
					printf("Cependant, vous portez d�j� un objet encombrant : l'objet a �t� d�pos� au sol.\n\n");
				else
					printf("Cependant votre sac est plein : l'objet a �t� d�pos� au sol.\n\n");
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
			printf(" Pas d'objets � utiliser !\n\n");
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
				else if (print_item(bag[i],2).compare("12") == 0) {printf("Prendre	");}
				else if (print_item(bag[i],2).compare("16") == 0) {printf("Utiliser	");}
				else if (print_item(bag[i],2).compare("17") == 0) {printf("Attaquer	");}
				else if (print_item(bag[i],2).compare("18") == 0) {printf("Prendre	");}
				else if (print_item(bag[i],2).compare("23") == 0) {printf("Attaquer	");}
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
	
	if (terror == true) printf("Impossible de fouiller, vous �tes litt�ralement t�tanis�(e) !\n"); else
	{
		number = rand()%4; // une chance sur 4 de rien trouv�
		
		if (number == 0)
		{
			printf("Apr�s des recherches �puisantes, vous n'avez rien trouv� d'autre que la vacuit� de ces moments perdus...\n\n");
		}
		else
		{
			if (location.compare("D�sert (zone �puis�)") == 0)
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
					ss >> proba; // recupere sa probabilit� en int (sur 100)
					
					number = rand()%100+1; // nb aleatoire entre 1 et 100
					//printf("objet : %s %s :",print_item(item_found,0).c_str(),print_item(item_found,3).c_str()); // d�tails
					if (proba >= number) // si la proba est plus �lev� que le nb g�n�r�, l'item est trouv�, sinon on recherche une nouvelle fois
					{
						okay = true;
					}
				}
			}
			printf("Apr�s de longues recherches, vous finissez par trouver %s par terre...\n\n",print_item(item_found,0).c_str());
			add_item(item_found);
			kilometers_exhausted[kilometers]++; // objet trouv� � ce kilom�tre, �puisement possible
		}
		drained = true;
	}
	wait_user();
}


void Die4laugh::a_dig_location_items()
{
	int number, final_item;
	
	clean();
	
	number = rand()%5; // 1 chance sur 5 de rien trouv�
	if (number == 0)
	{
		printf("\n\nApr�s des recherches �puisantes, vous n'avez rien trouv� d'autre que la vacuit� de ces moments perdus...\n\n");
	}
	else
	{
		if (location.compare("Petite maison") == 0)
		{
			int possible_items[11] = {1,2,3,6,13,15,16,17,19,35,36};
			final_item = open(possible_items, 11);
		}
		if (location.compare("Puits abandonn�") == 0)
		{
			int possible_items[11] = {3,3,3,3,3,3,25,25,25,25,29};
			final_item = open(possible_items, 11);
		}
		if (location.compare("Centrale hydrolique") == 0)
		{
			int possible_items[6] = {25,25,25,25,3,36};
			final_item = open(possible_items, 6);
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
			int possible_items[8] = {50,64,33,36,46,36,50,25};
			final_item = open(possible_items, 8);
		}
		if (location.compare("Carri�re effondr�e") == 0)
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
			int possible_items[5] = {75,38,39,79};
			final_item = open(possible_items, 5);
		}
		if (location.compare("Carlingue d'avion") == 0)
		{
			int possible_items[15] = {54,46,46,46,50,50,50,89,89,89,42,36,42,71,52};
			final_item = open(possible_items, 15);
		}
		if (location.compare("Chantiers � l'abandon") == 0)
		{
			int possible_items[15] = {42,42,42,50,50,53,53,27,27,64,66,80,89,35,36};
			final_item = open(possible_items, 15);
		}
		if (location.compare("Meubles KIELA") == 0)
		{
			int possible_items[9] = {73,73,61,90,65,67,21,71,35};
			final_item = open(possible_items, 9);
		}
		if (location.compare("Route barr�e") == 0)
		{
			int possible_items[9] = {62,62,62,50,50,35,35,36,36};
			final_item = open(possible_items, 9);
		}
		printf("\n\nLa peur vous prend aux tripes tandis que vous explorez %s...\nN�anmoins, �a n'aura pas �t� inutile puisque vous finissez par trouver %s.\n\n",location.c_str(),print_item(final_item,0).c_str());
		add_item(final_item);
	}
	drained_location = true;
	wait_user();

}


void Die4laugh::a_back_to_home()
{
	int i;
	
	clean();
	
	if (energy < energy_to_brb)
	{
		printf("Vous �tes trop fatigu�(e)...\n");
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
		printf("Vous �tes trop fatigu�(e) pour aller plus loin !\n\n");
		wait_user();
	}
	else if (stuck == true)
	{
		printf("Vous �tes submerg�s par les zombies, tentez d'en tuer, de fuir ou de vous �chapper...");
	}
	else
	{
		if (location.compare("Campement") == 0)
		{
			for (i=0; i<ground_size; i++)
			{
				ground_home[i] = ground[i]; // sauvegarde des objets au sol
			}
		}
		
		// zonzon
		if (location.compare("Campement") == 0)
		{
			monsters = 0;
		}
		
		reload_location();
		kilometers = kilometers + 1;
		stat_number_killometers++;
		energy = energy - 1;
		reset_ground();
		drained = false;
		drained_location = false;
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
			ground[i] = 0;
			counter --;
		}
		i++;
	}
	for (i=0; i<counter; i++)
	{
		sort_empty_racism(ground,ground_size);
		sort_empty_racism(bag,bag_size);
	}
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
	
	if (ch_waterwell == false) printf("[1] Puits : x2 Souche de bois pourrie + x1 D�bris m�talliques\n"); else printf("[-] (Puits)\n");
	printf(" -> Permet de r�cup�rer une ration d'eau par jour\n\n");
	if (ch_workshop == false) printf("[2] Atelier : x4 Planches tordues + x3 Ferraille\n"); else printf("[-] (Atelier)\n");
	printf(" -> Permet de transformer et d�monter des objets\n\n");
	printf("[X] Quitter\n\n");
	
	printf("\nQue voulez vous faire ?\n> ");
	fflush(stdin);
	scanf("%d",&int_choice);
	
	clean();
	
	if (int_choice == 1 && ch_waterwell == false)
	{
		if (count_camp_item(33) >= 2 && count_camp_item(34) >= 1)
		{
			remove_camp_item(33,2); remove_camp_item(34,1);
			ch_waterwell = true;
			printf("Le puits a �t� construit !\n");
		}
		else {printf("Vous n'avez pas les mat�riaux n�cessaires !\n");}
	}
	
	else if (int_choice == 2 && ch_workshop == false)
	{
		if (count_camp_item(35) >= 4 && count_camp_item(36) >= 3)
		{
			remove_camp_item(35,4); remove_camp_item(36,3);
			ch_workshop = true;
			printf("L'atelier a �t� construit !\n");
		}
		else {printf("Vous n'avez pas les mat�riaux n�cessaires !\n");}
	}
		
	sort_empty_racism(ground,ground_size); sort_empty_racism(bag,bag_size);
	wait_user();
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
	
	clean();
	
	printf("ATELIER:\n\n");
	
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

	if (metal_scrap > 0)
		printf("[1] Transformer :	(x%d) D�bris m�talliques		->   (x%d) Ferraille\n",metal_scrap,metal);
	if (wood_stump > 0)
		printf("[2] Transformer :	(x%d) Souche de bois pourrie	->   (x%d) Planche tordue\n",wood_stump,planks);
	if (nice_wood_stump > 0)
		printf("[3] Transformer :	(x%d) Souche en bon �tat		->   (x%d) Planche tordue\n",nice_wood_stump,planks);
	if (planks > 0)
		printf("[4] Transformer :	(x%d) Planche tordue			->   (x%d) Poutre rafistol�e\n",planks,beam);
	if (metal > 0)
		printf("[5] Transformer :	(x%d) Ferraille					->   (x%d) Structure m�tallique\n",metal,metallic_struct);
	if (beam > 0)
		printf("[6] Transformer :	(x%d) Poutre rafistol�e			->   (x%d) Planche tordue\n",beam,planks);
	if (metallic_struct > 0)
		printf("[7] Transformer :	(x%d) Structure m�tallique		->   (x%d) Ferraille\n",metallic_struct,metal);
	if (fragment_metal > 0)
		printf("[8] Transformer :	(x%d) Fragments de t�le			->   (x%d) Plaque de t�le\n",fragment_metal,sheet_metal);
	if (big_chest > 0)
		printf("[9] Ouvrir :		(x%d) Gros coffre en m�tal		->   ???\n",big_chest);
	printf("\n[X] Quitter\n\n");
	
	printf("\nQue voulez vous faire ?\n> ");
	fflush(stdin);
	scanf("%d",&int_choice);
	
	clean();
	
	if (int_choice > 0 && int_choice < 10)
	{
		if (energy < 3)
		{
			printf("Il vous faut %d �nergies pour travailler � l'atelier.\n",workshop_energy);
		}
		else if (int_choice == 1 && metal_scrap > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(34, 1);
			add_camp_item(36, 1);
			printf("Vous avez fabriqu� Ferraille � partir de D�bris m�talliques.\n");
		}
		else if (int_choice == 2 && wood_stump > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(33, 1);
			add_camp_item(35, 1);
			printf("Vous avez fabriqu� Planche tordue � partir de Souche de bois pourrie.\n");
		}
		else if (int_choice == 3 && nice_wood_stump > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(44, 1);
			add_camp_item(35, 1);
			printf("Vous avez fabriqu� Planche tordue � partir de Souche en bon �tat.\n");
		}
		else if (int_choice == 4 && planks > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(35, 1);
			add_camp_item(43, 1);
			printf("Vous avez fabriqu� Poutre rafistol�e � partir de Planche tordue.\n");
		}
		else if (int_choice == 5 && metal > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(36, 1);
			add_camp_item(42, 1);
			printf("Vous avez fabriqu� Structure m�tallique � partir de Ferraille.\n");
		}
		else if (int_choice == 6 && beam > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(43, 1);
			add_camp_item(36, 1);
			printf("Vous avez fabriqu� Planche tordue � partir de Poutre rafistol�e.\n");
		}
		else if (int_choice == 7 && metallic_struct > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(36, 1);
			add_camp_item(42, 1);
			printf("Vous avez fabriqu� Ferraille � partir de Structure m�tallique.\n");
		}
		else if (int_choice == 8 && fragment_metal > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(49, 1);
			add_camp_item(64, 1);
			printf("Vous avez fabriqu� Plaque de tole � partir de Fragment de tole.\n");
		}
		else if (int_choice == 9 && big_chest > 0)
		{
			energy = energy - workshop_energy;
			remove_camp_item(114, 1);
			add_camp_item(108, 1);
			printf("Vous avez trouv� Tron�onneuse incompl�te � partir de Gros coffre en m�tal.\n");
		}
		wait_user();
	}
	
	
}


void Die4laugh::a_runaway()
{	
	clean();
	
	if (terror == true) printf("Impossible de fuir, vous �tes litt�ralement t�tanis�(e) !\n"); else
	{
		if (injury == true)
		{
			printf("Vous ne pouvez plus fuir lorsque vous �tes bl�ss�(e).");
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
				printf("Miracle, vous avez r�ussi � slalomer entre les obstacles et un bipode sans aucune �gratinure !\nVous quittez la zone.\n");
			}
			else
			{
				printf("Pendant votre fuite, un zombie vous a lac�r� une partie du corps !\nIl faut quitter cet enfer et vite !!\n");
				stuck = false;
				injury = true;
				a_next_kilometer();
			}
		}
	}
	wait_user();
}


void Die4laugh::a_try_to_kill()
{
	clean();
	
	if (terror == true) printf("Impossible de vous battre, vous �tes litt�ralement t�tanis�(e) !\n"); else
	{
		if (energy <= 0)
		{
			printf("Vous n'avez pas assez d'�nergie pour vous battre.\n");
		} 
		else
		{
			if (rand()%10==0)
			{
				monsters --;
				printf("Au terme d'un effroyable affrontement, vous avez finalement r�ussi � faire chuter un zombie contre un rocher...\nSa t�te a litt�ralement explos� et son contenu s'est r�pandu sur vos chaussures ! Vous reculez en titubant, essoufl�(e) : un de moins... Han ... han ...\n");
				stat_number_kills = stat_number_kills + 1;
				stat_number_hardkills++;
			}
			else
			{
				printf("Vous agrippez � pleines mains l'une des horribles cr�ature mort-vivantes, le contact poisseux et collant de ses chairs putr�fi�es est insupportable...\nVous luttez, tentez de la repousser, mais rien n'y fait... Elle manque plusieurs fois de vous mordre ! Vous reculez, essoufl�(e) et d�moralis�(e)...\n");
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
        printf("[A] Utiliser un objet dans mon sac\n");
	}
	
	if (drained == false && deep_mode == false && location.compare("Campement") != 0 && stuck == false)
	{
        printf("[B] Fouiller les environs\n");
	}
	
	if (location.compare("D�sert...") != 0 && location.compare("Campement") != 0 && location.compare("D�sert (zone �puis�)") != 0 && drained_location == false)
	{
        printf("[C] Fouiller %s\n",location.c_str());
	}
	
	if (deep_mode == false && stuck == false)
	{
		printf("[D] Avancer\n");
	}
	
	if (deep_mode == false && location.compare("Campement") == 0)
	{
		printf("[E] Dormir\n");
	}
	
	if (deep_mode == false && location.compare("Campement") != 0)
	{
		printf("[E] Camper (%.2f%% de survie)\n",survival_chance_ouside);
	}
	
	if (deep_mode == true)
	{
		printf("[F] Retour\n");
	}
	
	if (deep_mode == false && location.compare("Campement") != 0 && stuck == false)
	{
		printf("[G] Retour au campement");
		if (kilometers != 0) {printf(" (%d �nergie)",energy_to_brb);}
		printf("\n");
	}
	
	if (deep_mode == false && location.compare("Campement") == 0)
	{
		printf("[H] Chantiers\n");
	}
	
	if (deep_mode == false && location.compare("Campement") == 0 && ch_waterwell == true && waterwell_today == false)
	{
		printf("[P] Prendre mon eau au puits\n");
	}
	
	if (deep_mode == false && location.compare("Campement") != 0 && stuck == true)
	{
		printf("[I] Prendre la fuite (danger)\n");
	}
	if (deep_mode == false && location.compare("Campement") != 0 && stuck == true)
	{
		printf("[J] Se battre � main nues (-1 �nergie)\n");
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
		ss >> int_choice;  // convertit les caract�res rentr�s en int si c'est un nombre
		
		if (deep_mode == false)
 		{
 			move_item(int_choice);
	    }
	    if (deep_mode == true)
 		{
			if (terror == true && print_item(bag[int_choice-1],2).compare("19") != 0) {printf("Impossible d'utiliser cet objet, vous �tes litt�ralement t�tanis�(e) !\n"); wait_user();}
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
			if (choice.compare("f") == 0 || choice.compare("F") == 0)
			{
				deep_mode = false;
				display_base();
			}
		}
		else
		{
			if (choice.compare("a") == 0 || choice.compare("A") == 0)
			{
				a_use_items();
			}
			if (choice.compare("b") == 0 || choice.compare("B") == 0)
			{
				if (drained == false && location.compare("Campement") != 0 && stuck == false)
				{
					a_dig_items();
				}
			}
			if (choice.compare("c") == 0 || choice.compare("C") == 0)
			{
				if (location.compare("D�sert...") != 0 && location.compare("Campement") != 0 && location.compare("D�sert (zone �puis�)") != 0 && drained_location == false)
				{
					a_dig_location_items();
				}
			}
			if (choice.compare("d") == 0 || choice.compare("D") == 0)
			{
				if (stuck == false)
				{
					a_next_kilometer();
				}
			}
			if (choice.compare("e") == 0 || choice.compare("E") == 0)
			{
				if (location.compare("Campement") == 0)
				{
					a_sleep_home();
				}
				if (location.compare("Campement") != 0)
				{
					a_sleep_outside();
				}
			}
			if (choice.compare("g") == 0 || choice.compare("G") == 0)
			{
				if (location.compare("Campement") != 0 && stuck == false)
				{
					a_back_to_home();
				}
			}
			if (choice.compare("h") == 0 || choice.compare("H") == 0)
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
			if (choice.compare("i") == 0 || choice.compare("I") == 0)
			{
				if (deep_mode == false && location.compare("Campement") != 0 && stuck == true)
				{
					a_runaway();
				}
			}
			if (choice.compare("j") == 0 || choice.compare("J") == 0)
			{
				if (deep_mode == false && location.compare("Campement") != 0 && stuck == true)
				{
					a_try_to_kill();
				}
			}
			if (choice.compare("t") == 0 || choice.compare("T") == 0)
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
		printf("\n/!\\ Attention, vous avez perdu le contr�le face aux zombies ! /!\\\n");
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
	int do_you_have_mine = -1;
	
	clean();
	
	// mort dans son lit
	if (location.compare("Campement") == 0)
	{
		rand_number = rand()%100;
		if (rand_number > display_camp_def) // si les zombies rentrent
		{
			for (i=0; i<ground_size; i++) //
			{
				if (print_item(ground[i],2).compare("15") == 0)
				{
					do_you_have_mine = i;
				}	
			}
			if (do_you_have_mine == (-1) || display_camp_def < 50) // si il n'y a pas de zombies OU trop de zombies
				death(6);
			else // la mine peut te sauver la nuit
			{
				printf("Ils s'en sont pris � vous, ils sont rentr�s dans le campement ! Un gros bruit a retenti, puis plus rien.\nLe petit groupe de zombies intrusif a march� sur une mine et cela vous a sauv� la vie !\n");
				ground[do_you_have_mine] = 0;
				sort_empty_racism(ground,ground_size);
				if ((count_camp_item(85) > 1 || count_camp_item(47) > 1) && rand()%2 == 0)
				{
					printf("\nCependant, mauvaise nouvelle : les autres explosifs du campement n'ont pas vraiment appr�ci�s l'explosion.\n");
					wait_user();
					death(7);
				}
			}
		}
	}
	
	// mort desydratation
	if (water_day == false)
	{
		if (thirst == false)
		{
			thirst = true;
		}
		else
		{
			if (big_thirst == false)
			{
				big_thirst = true;
			}
			else
			{	
				death(3);
			}
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
		rand_number = rand()%100;
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
	
	days = days + 1;
	
	survival_chance_ouside = (100*(kilometers/10.0)) *  (1/(days*0.5));
	survival_chance_ouside = survival_chance_ouside + day_outside*5; // jour pass� dehors baisse les chances
	if (survival_chance_ouside >= 100) {survival_chance_ouside = 100;}
	
	//decheance des defenses
	if (days > 2)
	{
		camp_def = camp_def - (rand()%5 * days/3);
	}
	
	
	//eteint les torches
	for (int i=0; i<bag_size; i++)
	{
		if (print_item(bag[i],2).compare("68") == 0)
			bag[i] = 69;
	}
	for (int i=0; i<ground_size; i++)
	{
		if (print_item(ground[i],2).compare("68") == 0)
			ground[i] = 69;
	}
	water_day = false;
	food_day = false;
	drug_day = false;
	convalescent = false;
	energy = energy_max;
	waterwell_today = false;
	meds = false;
	if (alcohol == true) {alcohol = false; hangover = true;}
	else if (hangover == true) {hangover = false;}
	
	printf("---------------\nJOUR %d\n---------------\n\n",days);
	wait_user();
}


void Die4laugh::death(int why)
{
	int choice;
	clean();
	printf("F�licitations, vous �tes mort(e) !!\n\n");
	if (why == 1)
	{
		printf("\"Peu apr�s minuit, un silence pesant s'est abattu tout autour de vous, comme si toute vie venait de s'�teindre\nbrusquement. La nuit s'est faite glaciale... Puis vous les avez vus, des dizaines... des centaines titubant\nvers vous.. Leurs mains vous saisissant, agrippant, tirant, arrachant... Puis ils vous ont tra�n�\navec eux toute la nuit, pour vous d�vorer encore vivant au petit matin.\"");
		stat_number_death_outside++;
	}
	if (why == 2)
	{
		printf("Les drogues c'est agr�able quand on en a. D�s qu'on a �puis� ses r�serves, c'est une autre histoire... D'abord\non tremble, puis on commence � se vider de son contenu toutes les dix minutes. Quand la situation de\nmanque empire, on finit par perdre totalement la raison. C'est comme �a qu'on se retrouve � avaler des\ncailloux en pensant avoir trouv� des st�ro�des.");
		stat_number_death_drugs++;
	}
	if (why == 3)
	{
		printf("Le manque d'eau est r�ellement quelque chose de sale. Durant vos derni�res heures, votre peau a commenc� � se\ndess�cher et � se craqueler, puis votre langue a gonfl�. vous avez bien essay� de trouver n'importe quoi\n� boire. Sans succ�s. Certains diront m�me vous avoir vu en train d'avaler du sable � pleines poign�es avant\nde vous effondrer, raide mort(e).");
		stat_number_death_water++;
	}
	if (why == 4)
	{
		printf("Argh ! On dirait bien qu'une silhouette s'�tait gliss�e derri�re vous ! Sans avoir eu le temps de r�agir, quelqu'un,\nou quelque chose s'est jet� sur vous, vous a rou� de coups avant de vous d�vorer alors que vous �tiez encore conscient(e).\nAvant de sombrer dans la mort, une question vous a assailli : quel go�t pouvez-vous bien avoir ?");
		stat_number_death_outside++;
	}
	if (why == 5)
	{
		printf("Petit � petit, l'horrible maladie vous a rong� de l'int�rieur... Rapidement, des signes de l'infection sont apparus sur votre corps :\nplaies, h�matomes, chairs qui se d�composent... Jusqu'� l'agonie finale qui aura dur� plusieurs heures cette nuit.\nLa mort en est presque un soulagement.");
		stat_number_death_ill++;
	}
	if (why == 6)
	{
		printf("Clo�tr� dans votre campement, vous esp�riez qu'ils ne passeraient pas... Vous les avez entendus grogner, renifler � votre porte...\nPuis plus rien. Une cloison proche a alors brusquement vol� en �clats. Mal barricad�e s�rement...\nVous avez hurl�, ils vous ont laiss� vous d�battre puis vous ont plaqu� contre votre lit.\nLentement, ils vous ont d�vor�. Aucun survivant n'est venu � votre aide. Personne.");
		stat_number_death_inside++;
	}
	if (why == 7)
	{
		printf("Les cr�atures de ce monde ne vous aimaient pas. Les zombies, comme les survivants, cherchant � vous �viter. Enfin, pas cette nuit.\nDeux d'entre eux vous ont violemment saut� dessus, tandis que deux autres ont saut� sur une mine.\nL'explosion s'est �tendue sur certains objets et d�truit le campement ainsi que tout ce qui �tait en son sein.\nC'est ce qu'on appelle partir en beaut�.");
		stat_number_death_bomb++;
	}
	if (why == 8)
	{
		printf("Plut�t que continuer � vivre dans ce monde de losers, vous avez fait le choix de vous simplifier la vie...\nEn l'�courtant un peu. Bof, apr�s tout, une journ�e de plus ou de moins...");
		stat_number_death_suicide++;
	}
	printf("\n\nVous avez surv�cu %d jours. Voulez vous retourner au menu ?\n[1] Oui\n[x] Non\n> ",days);
	scanf("%d",&choice);
	fstat_write();
	if (days > stat_max_days)
		stat_max_days = days;
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
	if (display_camp_def > 100) display_camp_def = 100;
	
	survival_chance_ouside = (100*(kilometers/10.0)) * (1/(days*0.5)) - (monsters*10);
	if (terror == true) {survival_chance_ouside = survival_chance_ouside-90;}
	//printf("%f * %f = %f",(100*(kilometers/10.0)),(1/(days*0.5)),survival_chance_ouside);
	if (survival_chance_ouside >= 100) {survival_chance_ouside = 100;}
	if (survival_chance_ouside <= 0) {survival_chance_ouside = 0;}
	
	// gestion slots suppl�mentaires
	slot1 = false; slot2 = false;
	for (int i=0; i<bag_size; i++)
	{
		if (print_item(bag[i],0).compare("Sac suppl�mentaire") == 0 || print_item(bag[i],0).compare("Ceinture � poches") == 0)
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
}


void Die4laugh::display_base()
{
	bool done = false;
	while (!done)
	{
		clean();
		
		//actualisation chaque tour
		refresh_at_display();
		
		// affichage
		stuck_f();
		printf("Jour		: %d\n",days);
		if (kilometers != 0) {printf("Kilom�tres	: %d\n",kilometers);}
		printf("Energie		: %d/%d\n",energy,energy_max);
		printf("Lieu		: %s",location.c_str());
		if (location.compare("Campement") != 0) {if (terror == false) printf("\nZombies		: %d / %d",monsters,monsters_control); else printf("\nZombies		: %d / TERRORISE(E)",monsters);}
		else {printf(" (survie : %d%%   d�fenses : %d)\n",display_camp_def,camp_defadd);}
		printf("\nMes �tats :\n");
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
	Die4laugh the_game;
	
	return 0;
}
