#include<bits/stdc++.h>
using namespace std;

string rche,xche;
string rwei,xwei;
int f1,f2,f3;

int main()
{
    //444444444444444444444444444444444444444
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>rche>>rwei>>xche>>xwei;

    if(rche==xche){
        cout<<1;
        f1=1;
    }
	else
	{
    	cout<<0;
	}

    if(rwei[0]==xwei[0] && rwei[1]==xwei[1] && f1==1){
        cout<<1;
        f2=1;
    }
	else
	{
    	cout<<0;
	}

	if(((('A'<=rwei[2] && rwei[2]<='C') && ('A'<=xwei[2] && xwei[2]<='C')) || (('D'<=rwei[2] && rwei[2]<='F') && ('D'<=xwei[2] && xwei[2]<='F'))) && f2==1){
        cout<<1;
        f3=1;
    }
	else
	{
    	cout<<0;
	}

	if(((rwei[2]== 'A' && xwei[2]== 'B') || (rwei[2]== 'B' && xwei[2]== 'A') ||(rwei[2]== 'B' && xwei[2]== 'C') || (rwei[2]== 'C' && xwei[2]== 'B') ||(rwei[2]== 'D' && xwei[2]== 'F') ||(rwei[2]== 'F' && xwei[2]== 'D'))  && f3==1){
        cout<<1;
    }
	else
	{
    	cout<<0;
	}

    return 0;
}
