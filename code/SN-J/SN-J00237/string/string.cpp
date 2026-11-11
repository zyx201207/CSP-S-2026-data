#include <bits/stdc++.h>
using namespace std;
long long m[100000000],e[100000],cnt,c,g,h,num;
int n;
char f[100000];
int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>e[i]>>f[i];
	}
	for(int i=0;i<n;i++){
		cnt+=e[i];
	}
	if(cnt%2==0){
		g=cnt/2;
		h=g+1;
		while(g>=1&&h<=n){
			if(f[g]!=f[h]) num++;
			g--;
			h++;
		}
		num++;
	} 
	else{
		g=cnt/2;
		h=cnt/2+2;
		while(g<=1&&h>=n){
			if(f[g]!=f[h]) num++;
			g--;
			h++;
		}
	}
	cout<<num; 
} 
