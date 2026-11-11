#include<bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

const ll Maxn=1e5+10;

ll n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cout<<rand()%10<<' ';
	}

	return 0;
}

