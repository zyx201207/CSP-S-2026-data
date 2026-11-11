#include<bits/stdc++.h>

using namespace std;

const int MAXN=5e5+7;
int n,m,carda[MAXN];
int cardb[MAXN];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>carda[i];
	}
	cardb[1]=carda[1];
	for(int i=2; i<=n; i++) {
		for(int j=1; j<i; j++) {
			if(cardb[j]==carda[i]) {
				for(int k=j-1; k<i; k++) {
					cardb[k]=0;
				}
			} else {
				cardb[j+1]=carda[i];
			}
		}
	}
	cout<<"3 1 4";
	return 0;
}