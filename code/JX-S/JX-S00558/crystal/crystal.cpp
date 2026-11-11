#include<bits/stdc++.h>
using namespace std;
vector<long long>a;
vector<long long>key;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,n,b,l,k=0;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>b;
		a.push_back(b);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<m;i++){
		l=n;
		for(int j=i-1;j>=0;j--){
			if(l>=a[i]-a[j]){
				k+=1;
				l-=a[i]-a[j];	
			}
			else {
				break;
			}
		}
		key.push_back(k);
		k=0;
	}
	sort(key.begin(),key.end());
	cout<<key[key.size()-1]+1;
}
