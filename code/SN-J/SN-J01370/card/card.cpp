#include<bits/stdc++.h> 

using namespace std;

queue <long long> desk;
long long card[100005];
long long desk_card[100005];
long long n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>card[i];
		desk_card[card[i]]++;
	}
	for(int i=n;i>0;i++){
		cout<<desk_card[i]<<" ";
	}
return 0;
}

