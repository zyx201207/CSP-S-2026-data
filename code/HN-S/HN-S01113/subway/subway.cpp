#include<iostream>
#include<cstdio>

using namespace std;

const int MAX_nod=5e2+5;
const int MAX_dis=8e8+5;

long long int junk;
long long int line;
long long int node;
long long int most;
long long int plan;

long long int firs[MAX_nod];

long long int mapp[MAX_nod][MAX_nod];

struct each_line{
	long long int sta;
	long long int tho;
};
each_line eali[MAX_nod];

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>junk;
	cin>>line;
	cin>>node;
	cin>>most;
	cin>>plan;
	
	for(long long int i=1;i<=node;i++)
		for(long long int j=1;j<=node;j++)
			mapp[i][j]=MAX_dis;
	for(long long int i=1;i<=node;i++)
		mapp[i][i]=0;
		
	for(long long int i=1;i<=node;i++)
		cin>>firs[i];
	
	for(long long int i=1;i<=line;i++){
		
		long long int pass;
		cin>>pass;
		
		for(long long int j=1;j<=pass;j++){
			cin>>eali[j].sta;
			cin>>eali[j].tho;
		}
		
		for(long long int u=1;u<=pass;u++){
			for(long long int v=u+1;v<=pass;v++){
				
				mapp[eali[u].sta][eali[v].sta]=eali[u].tho+eali[v].tho;
				mapp[eali[v].sta][eali[u].sta]=eali[u].tho+eali[v].tho;
			}
		}
	}
	/*
	for(int i=1;i<=node;i++){
		for(int j=1;j<=node;j++)
			cout<<mapp[i][j]<<" ";
		cout<<endl;
	}*/
	
	for(long long int k=1;k<=node;k++)
		for(long long int i=1;i<=node;i++)
			for(long long int j=1;j<node;j++){
				if(mapp[i][k]!=MAX_dis && mapp[k][j]!=MAX_dis){
					mapp[i][j]=min(mapp[i][j],mapp[i][k]+mapp[k][j]);
					mapp[j][i]=min(mapp[j][i],mapp[i][k]+mapp[k][j]);
				}
			}
	/*
	cout<<endl;
	for(int i=1;i<=node;i++){
		for(int j=1;j<=node;j++)
			cout<<mapp[i][j]<<" ";
		cout<<endl;
	}*/
	
	for(long long int i=1;i<=plan;i++){
		long long int u,v;
		cin>>u>>v;
		cout<<mapp[u][v]+firs[u]+firs[v]<<endl;
	}
	
	return 0;
}
