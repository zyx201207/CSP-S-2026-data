#include<fstream>
#include<math.h>
using namespace std;
int *a,*t,n,d;
int dfs(int u,int v)
{
	int mm=0;
	if(u==v)return 1;
	int s=10000000000;
	for(int i=0;i<n;i++){
		int tt=100000000000;
		if(abs(a[i]-a[u])<=d&&t[i]!=-1){
			t[i]=-1;
			tt=dfs(i,v)+1;
		
		}
		for(int i=0;i<n;i++){
			t[i]=a[i];
		}
		if(s>tt){s=tt;mm=1;}
		else if(s==tt)mm++;
	}
	return mm;
}
int main(){
	ifstream fin("migrate.in");
	ofstream fout("migrate.out");
	int c,r;
	fin>>c>>r;
	while(r--){
		int SUM=0;
		fin>>n>>d;
		a=new int(n);
		t=new int(n);
		for(int i=0;i<n;i++){
			fin>>a[i];
			t[i]=a[i];
		}
		for(int i=1;i<n;i++)
			for(int j=0;j<i;j++)
			{
				if(dfs(i,j)==2)SUM++;
			}
		fout<<SUM;
	}
	return 0;
}
