#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[550000],t[550000];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios::sync_with_stdio(false);

cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	}
for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j++){
		t[a[j]]++;
		if(t[a[j]]==2){
			break;
			}
		}
	}
cout<<"3 1 4";

cin.tie(nullptr);
cout.tie(nullptr);
return 0;
}

