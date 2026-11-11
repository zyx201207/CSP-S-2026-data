#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
map<int,int> mp;
int n,m;
vector<int> arr(500005);
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>arr[i];
for(int i=1;i<=n;i++){
	map<int,bool> mp1;
	vector<int> arr1(500005);
	int arr1_num=0;
	for(int j=i;j<=n;j++){
		if(mp1.count(arr[j])&&mp1[arr[j]]){
			for(int ii=arr1_num-1;ii>=0;ii--){
				mp1[arr1[ii]]=false;
				arr1[ii]=-1;	
				if(arr1[ii]==arr[j]) break;
		    }
		}
	    arr1[arr1_num]=arr[j];
	    arr1_num++; 
	    mp1[arr[j]]=true;
	}
	for(int ii=0;ii<arr1_num;ii++){
		if(arr1[ii]>0) mp[arr1[ii]]++;
	}
}
for(int i=1;i<=m;i++) cout<<mp[i]<<" "; 
	return 0;
}
