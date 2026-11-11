#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s[20000];
string b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int l,t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=i;j<=n;j++){
			int w=-1;
			w=b.find(a[j]);
			if(w!=-1){
				t=i;
				b[t]=a[j];
			}else{
				b[++t]=a[j];
			}
		}
		for(int q=1;q<=m;q++){
			int x=-1;
			x=b.find(q);
			if(x!=-1){
				s[q]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
 
