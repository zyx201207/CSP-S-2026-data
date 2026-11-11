#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[500010];
int ar[500010];
int arr1[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	int b=0;
	for(int i=2;i<=n;i++){
		if(arr[i-1]>arr[i]){
			b=1;
		}
	}
	if(b==0){
		for(int i=1;i<=n;i++){
			cout << i << " ";
		}
		return 0;
	}
	int nn=n;
	int a=0;
	while(nn--){
		a++;
		for(int i=1;i<=n;i++){
			ar[i]=0;
		}
		stack <int> s;
		for(int i=a;i<=n;i++){
			if(ar[arr[i]]>=1){
				while(!s.empty()&&s.top()!=arr[i]){
					ar[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(arr[i]);
				ar[arr[i]]++;
			}
		}
		while(!s.empty()){
			arr1[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout << arr1[i] << " ";
	}
	return 0;
}
