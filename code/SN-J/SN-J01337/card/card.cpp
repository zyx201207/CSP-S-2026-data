#include<bits/stdc++.h>
using namespace std;
long long an[600010],ang[600010],am[400010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>an[i];
	}
	long long game=n;
	for(long long i=0;i<n;i++){
		for(long long j=i;j<n;j++){
			for(long long k=0;k<game;++k){
				if(an[k]!=an[j]){
					ang[k]=an[k];
				}
				else{
					game=k;
					break;
				}
			}
			game++;
			ang[game]=an[j];
		}
		
		for(long long z=0;z<game;z++){
			am[ang[z]]++;
		}
	}
	for(long long z=1;z<=m;z++){
			cout<<am[z]<<" ";
		}
	return 0;
}
#¹Ø×¢ÓÀ³ûËþ·ÆÐ»Ð»ß÷
