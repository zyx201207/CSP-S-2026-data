#include<iostream>
#include<cstring>
using namespace std;
struct n{
	int a;
	string b;
	int c;
	string d;
};

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n sit;
	cin>>sit.a>>sit.b>>sit.c>>sit.d;
	int x[5]={0};
	if(sit.a==sit.c) 
	{
		x[1]=1;
		if(sit.b[0]==sit.d[0]&&sit.b[1]==sit.d[1])
		{
			x[2]=1;
			if('A'<=sit.b[2]&&sit.b[2]<='C'&&'A'<=sit.d[2]&&sit.d[2]<='C'){	
				x[3]=1;
				if(sit.b[2]-sit.d[2]==1||sit.b[2]-sit.d[2]==-1) x[4]=1;
			}
			else if('D'<=sit.b[2]&&sit.b[3]<='E'&&'D'<=sit.d[2]&&sit.d[2]<='E') x[3]=1;
		}
	}
	cout<<x[1]<<" "<<x[2]<<" "<<x[3]<<" "<<x[4];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
