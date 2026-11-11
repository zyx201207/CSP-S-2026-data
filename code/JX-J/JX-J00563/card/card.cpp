#include<bits/stdc++.h>
using namespace std;
int num[300005];
int a[500005];
int n,m;
void pl(int b,int e){
	vector<int>mp;
	int l=0,s=0;
	int st[e+1]={};
	for(int j=b;j<e;j++){
		if(st[a[j]]==0){
			st[a[j]]=1;
			if(s<=l+5){
                mp.push_back(0);
                s++;
			}
            l++;
            mp[l]=a[j];

		}
		else{
			while(mp[l]!=a[j]){
				mp[a[j]]=0;
				l--;
			}
		}
	}
	for(int j=0;j<=m;j++){
		num[j]+=st[j];
	}
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		pl(i,n);
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
