#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> cnt;
int n,m;
void play(int index){
	vector<int> a=arr;
	
	for(int i=n-1; i>index; i--){
		for(int j=index; j<i; j++){
			if(a[i]==a[j]){
				for(int k=j; k<i; k++){
					a[k]=0;
				}
			}
		}
	}
	
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	for(int j=index; j<n; j++){
		cnt[a[j]]++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	arr.resize(n+5);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cnt.resize(m);
	
	for(int i=0; i<n; i++){
		play(i);
	}

	for(int i=1; i<=m; i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
