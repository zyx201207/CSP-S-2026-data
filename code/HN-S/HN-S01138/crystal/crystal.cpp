#include<bits/stdc++.h>
using namespace std;
long long a,m,s,g,h,l;
long long w[1000000000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>s;
	long long f[a-1];
	long long q[a-1];
	long long d=10000000000;
	for(int i=0;i<a;i++){
		cin>>f[i];
		q[i]=f[i];
	}
	sort(f+1,f+a+1);
	while(m==0){
		for(int i=0;i<=a;i++){
			for(int j=0;j<=a;j++){
				if(f[j]-f[i]<d&&f[j]-f[i]>0){
					d=f[j]-f[i];
					g=i;
					h=j;
				}else if(f[i]-f[j]<d&&f[i]-f[j]>0){
					d=f[i]-f[j];
					g=j;
					h=i;
				}
			}
		}
		if(s>0){
			s--;
			f[h]=f[g]+f[h];
			f[g]=f[g]+1000000000;
			g=g-g;
			h=h-h;
			d=d-d;
			d=d+1000000000;
		}else{
			m++;
		}
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<i;j++){
			if(f[i]==f[j]&&f[i]!=1000000000&&f[j]!=1000000000){
				w[i]++;
			}
		}
	}
	sort(w+1,w+a+1);
	cout<<w[a];
	return 0;
}
