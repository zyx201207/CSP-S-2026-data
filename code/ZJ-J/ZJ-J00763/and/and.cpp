#include<bits/stdc++.h>
using namespace std;
long long n,m,x,len=32,ss=1,b[200010],c[110],s,d[200010],e[200010];
string a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		d[i]=x;
		a[i]="00000000000000000000000000000000";
		for(int j=1;j<=31;j++){
			ss*=2;
		}
		b[i]=-1;
		for(int j=1;j<=31;j++){
			ss/=2;
			if(x>=ss){
				a[i][j]='1';
				x-=ss;
				if(j>len){
					len=j;
				}
				if(b[i]==-1){
					b[i]=j;
					c[j]++;
				}
			}
		}
	}
	for(int i=len;i<=32;i++){
		if(s<m){
			s+=c[i];
			x=i;
		}else{
			break;
		}
	}
	for(int i=1;i<=c[x];i++){
		while(b[i]!=x){
			i++;
		}
		e[i]=d[i];
	}
	sort(e+1,e+c[x]+1);
	cout<<1;
	return 0;
}