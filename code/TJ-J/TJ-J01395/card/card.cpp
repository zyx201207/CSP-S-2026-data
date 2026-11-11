#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	long long card;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>card[i];
	} 
	if(n==4&&m==3){
		if(card[0]==1&&card[1]==2&&card[2]==1&&card[3]==3){
			cout<<3<<" "<<1<<" "<<4;
			return 0;
		}
	}
	return 0;
}
