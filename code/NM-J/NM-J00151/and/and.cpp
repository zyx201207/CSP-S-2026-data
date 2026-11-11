#include<bits/stdc++.h>
using namespace std;
vector <int> a;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

	int n,m,k;
	cin>>n>>m;
	for(int i=0;i<n;i++){
        cin>>a[i];
	}
	sort(a.begin(),a.end());
	k=a[0];
	for(int i=1;i<m;i++){
        k&=a[i];
	}
	cout<<k;

	return 0;
}
