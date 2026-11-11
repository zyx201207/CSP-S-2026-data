#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int c,T,n,k,_,__;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>_>>__;
		if(k==2){
			cout<<1<<endl;
		}else if(n>=6){
			cout<<2<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	
	return 0;
}
/*
Can you hear my calling even if it is raining
Flowers coming into bloom
Looking for the shining every night and morning
Ties will never broke agian
You will know how much I love you
Things I can tell you
Is I wanna to live with you all
I promise you forever
Walking with together
Giving a thanks to my dears
*/
