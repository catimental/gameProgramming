#include <stdio.h>
#include <string.h>

//struct trump {
//	int order;
//	char shape[3];
//	int number;
//};
typedef struct trump {
	int order;
	char shape[3];
	int number;
} trump;

void make_card(trump m_card[]);
void display_card(trump m_card[]);
void display_random_card(trump m_card[]);
int main(void) {
	trump card[52];
	
	make_card(card);
	display_random_card(card);
	//display_card(card);
	return 0;
}

void display_random_card(trump m_card[]) 
{
	int card_indexies[5];
	int i, j;
	int random_index;
	int is_valid_index = 1;
	for(i = 0; i<5; i++) 
	{
		is_valid_index = 1;
		while(1) 
		{
			random_index = rand() % 52;
			for( j = 0; j<5; j++) 
			{
				if(card_indexies[j] == random_index) 
				{
					is_valid_index = 0;
				}				
			}
			if(is_valid_index == 1) 
			{
				card_indexies[i] = random_index;
				break;
			}			
		}
	}
	for(i = 0; i<5; i++) 
	{		
		int index = card_indexies[i];
		
		printf("%s", m_card[index].shape);
		
		if(10 < m_card[index].number)
			printf("%-2c", m_card[index].number);
		else
			printf("%-2d", m_card[index].number);
		printf("\n");
	}
}

void make_card(trump m_card[])
{
	int i, j;
	char shape[4][3] = {"¢¼", "¡ß", "¢¾", "¢À"};
	
	for(i = 0; i<4; i++) 
	{
		for(j = i*13; j<i*13+13; j++) 
		{
			m_card[j].order = i;
			strcpy(m_card[j].shape, shape[i]);
			m_card[j].number = j%13+1;
			switch(m_card[j].number) 
			{
				case 1:
					m_card[j].number = 'A';
					break;
				case 11:
					m_card[j].number = 'J';
					break;
				case 12:
					m_card[j].number = 'Q';
					break;
				case 13:
					m_card[j].number = 'K';
					break;
			}
		}
	} 
}

void display_card(trump m_card[])
{
	int i, count = 0;
	for(i = 0; i<52; i++) 
	{
		printf("%s", m_card[i].shape);
		
		if(10 < m_card[i].number)
			printf("%-2c", m_card[i].number);
		else
			printf("%-2d", m_card[i].number);
		count++;
		
		if(i%13+1 == 13) 
		{
			printf("%n");
			count = 0;
		}
	}
}

