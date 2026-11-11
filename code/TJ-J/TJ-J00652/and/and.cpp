#include<bits/stdc++.h>
using namespace std;
void read(long long &a){
	char ch;
	int f=1;
	for(;ch=getchar();){
		if('0'<=ch&&ch<='9'){
			a=ch-'0';
			break;
		}else if(ch=='-'){
			f*=-1;
		}
	}for(;ch=getchar();){
		if('0'>ch||ch>'9'){
			a*=f;
			return ;
		}a=a*10+(ch-'0');
	}
}long long n,m,a,Max;
bool b[300000][40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++){
		cin>>a;
		int s=0;
		for(;a;){
			s++;
			b[i][s]=a%2;
			a/=2;
		}
	}int S=n,s=0;
	for(int i=35;i>=1;i--){
		int z=0;s=0;
		for(int j=1;j<=S;j++){
			if(b[j][i]){
				s++;
			}
		}if(s>=m){
			S=s;
			z=1;
			for(int j=1;j<=S;j++){
				if(b[j][i]){
					for(int k=1;k<=35;k++){
						b[s][k]=b[j][k];
					}
				}
			}
		}Max=Max*2+z;
	}cout<<Max;
} 
