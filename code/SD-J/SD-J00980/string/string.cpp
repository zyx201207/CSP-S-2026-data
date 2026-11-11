#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,x,cnt;
char a[200100];
map<pair<char,int>,int>t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		cin>>a[i];
		t[{a[i],i}]+=x;
	}
	int l=1,r=n;
	while(l<r){
		if(t[{a[l],l}]>=t[{a[r],r}]){
			if(a[l]!=a[r])cnt+=t[{a[r],r}];
			t[{a[l],l}]-=t[{a[r],r}];
			t[{a[r],r}]=0;	
		}else if(t[{a[l],l}]<t[{a[r],r}]){
			if(a[l]!=a[r])cnt+=t[{a[l],l}];
			t[{a[r],r}]-=t[{a[l],l}];
			t[{a[l],l}]=0;	
		}
		if(t[{a[l],l}]==0)l++;
		if(t[{a[r],r}]==0)r--;
	}
	cout<<cnt;
	return 0;
}

