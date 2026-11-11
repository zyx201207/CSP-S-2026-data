#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t; 
	int a[maxn],b[maxn];
	int mna=maxn,mnb=maxn;
	for(int i=0;i<t;i++){
		int e,d;
		cin>>e>>d;
		for(int j=1;j<e;j++){
			cin>>a[i]>>b[i];
			mna=min(mna,a[i]);
			mnb=min(mnb,b[i]);
		}
	}
	cout<<mna<<"\n"<<mnb;
	return 0;
} 
