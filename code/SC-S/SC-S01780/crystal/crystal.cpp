#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
set<int>asd;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	int i=0,j=0,as=0,ans=0,num=0;
	int x=0;
	while(i==n ||j==n){
		if(as<=m){
			j++;
			num++;
			asd.insert(num);
			ans+=a[j];
			if(x!=0){
				as+=max(a[j],x)-min(a[j],x);
				x=ans/num;
			}else{
				as=0;
				x=ans/num;
			}
		}else{
			i++;
			num--;
		}
	}
	for(int asd : x){
		cout<<x;
		return 0;
	}
	return 0;
}