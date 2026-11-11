#include<bits/stdc++.h>
using namespace std;

const int N=2000010;
int x[N];
int hsh[N];
int qz[N];
int d;
int s;

int num=0;


void printf(int b){
	bool flag=0;
	int v=0;
	for(int i=1;i<=b;i++){
		v+=hsh[i];
	}
	if(v==s){
		for(int i=1;i<=b;i++){
			if(hsh[i]==0){
				flag=1;
			} 
		}
		
		if(flag==0){
			for(int i=1;i<=b;i++){
				if(hsh[i]>d){
					flag=1;
					break;
				}
			} 
			
		} 
		if(flag==0){
			num++;
		}
	}
}

void dfs(int a,int b,int c){
	for(int i=c;i<=b;i++){
		for(int j=1;j<=a;j++){
			hsh[i]=j;
			if(a-j>=0 && b-1>=0){
				dfs(a-j,b,i+1);
				printf(b);
			}
			hsh[i]=0;
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	
	int sum=0;
	while(t--){
		memset(qz,0,sizeof(qz));
		sum=0;
		int n;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		qz[1]=0;
		for(int i=2;i<=n;i++) qz[i]=x[i]-x[1];
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s=qz[j]-qz[i];
				int cs=s/2+s%2;
				memset(hsh,0,sizeof(hsh));
				dfs(s,cs,1);
				if(num==2) sum++;
			}
		}
		cout<<sum<<endl;
	}
	
	
	return 0;
}
