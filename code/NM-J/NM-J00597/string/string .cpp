#include<bits/stdc++.h>
using namespace std;
long long n,s[100005],b=0,zs=0,cs=0,x,y;
char z[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i]>>z[i];
		zs+=s[i];
		cs++;
	}
	x=0;
	y=cs-1;
	for(;zs>0;){
		if(s[x]>=s[y]){
			if(z[x]!=z[y]){
				b+=s[y];
			}
			zs-=2*s[y];
			s[x]-=s[y];
			s[y]=0;
			y--;
			if(s[x]==0){
				x++;
			}
		}
		else{
			if(z[x]!=z[y]){
				b+=s[x];
			}
			zs-=2*s[x];
			s[y]-=s[x];
			s[x]=0;
			x++;
		}
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
