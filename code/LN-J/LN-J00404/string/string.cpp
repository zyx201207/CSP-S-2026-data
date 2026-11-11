#include<bits/stdc++.h>
using namespace std;
int num=0,z[26],zs;
bool pd(string f[10000005],int g){
	for(int h=0;h<=g/2;h++) if(f[h]==f[g-h]) return 1;
}
int hw(string d[10000005],int e){
	if(pd[d,e]) return num;
	else {
		for(int m=0;m<e;m++){
			d[m]=z[m%zs];
			hw[d,e];
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	string s[10000005];
	int n,a,b,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s[cnt]=b;
			cnt++;
			for(int l=0;l<zs;l++){
				if(l==26 && z[l]!=b){
					z[i]=b;
					zs++;
				}
				}
		}
}
	cout<<hw(s,cnt);
	return 0;
}
