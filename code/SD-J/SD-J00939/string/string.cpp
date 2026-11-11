#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+3;
struct node{int num;char str;}arr[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){	
		int x;char s;
		cin>>x>>s;
		arr[i]=(node){x,s};
	}
	int p=1,q=n;
	int ans=0;
	while(p<=q){
		if(arr[p].num>arr[q].num){
			if(arr[p].str!=arr[q].str)
				ans+=arr[q].num;
			arr[p].num-=arr[q].num;q--;
		}
		else if(arr[p].num<arr[q].num){
			if(arr[p].str!=arr[q].str)
				ans+=arr[p].num;
			arr[q].num-=arr[p].num;p++;
		}
		else{
			if(arr[p].str!=arr[q].str)
				ans+=arr[p].num;
			p++;q--;			
		}
	}
	cout<<ans<<"\n";
	return 0;
}

