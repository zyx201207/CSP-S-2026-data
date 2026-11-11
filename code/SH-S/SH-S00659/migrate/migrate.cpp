#include<bits/stdc++.h>
using namespace std;
const int N=2e6+3;
int c,T,n,d,a[N],ans;
bool t;
void f(int x,int y,int goal,int cet){
	if(x==goal){
		if(y==goal&&cet) ans++,t=1;
		else return ; 
	}
	if(y>=goal||x>=goal){
		return ; 
	}
	for(int i=x+1;i<=goal;i++){
		if(a[i]-a[x]<=d){
			for(int j=y+1;j<=goal;j++){
				if(a[j]-a[y]<=d){
					if(i!=j) f(i,j,goal,cet+1);
					else f(i,j,goal,cet);
					if(t)return;	
				}else{
					return ;
				}
			}
		}else{
			return ;
		}
	}
}
int main(){
	ifstream fin("migrate.in");
	ofstream fout("migrate.out");
	fin>>c>>T;
	if(c==11||c==12){
		while(T--){
			fin>>n>>d;
			ans=0;
			int u;
			for(int i=1;i<=n;i++){
				fin>>a[i];
				if(a[i]-a[1]>d)u=i-1;
			} 
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					if(a[i]-a[i-1]<=d&&(j-i)%u!=0)ans++;
				}
			}
			fout<<ans;
		}
	}
	while(T--){
		fin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) fin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				t=0;
				f(i,i,j,0);
			}
		}
		fout<<ans<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
