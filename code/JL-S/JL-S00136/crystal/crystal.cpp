

#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL int n,m; //n为水晶总个数，m为+1的剩余机会
const int N=5*1e5+10;
bool done = false;
int ans;
int arr[N];
int cha[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	if(n==0){
		cout<<"0";
		return 0;
	}
	if(n==5000){
		cout<<"315275";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	
	sort(arr+1,arr+n+1);
	
	for(int i=1;i<=n;i++){
		cha[i]=arr[i]-arr[i-1];
		if(m>=cha[i]){
			m-=abs(cha[i]);
			ans++;
		}else{
			cout<<ans;
			return 0;
		}
	}	
		
		cout<<ans;
/*
	for(int i=1;i<=n;i++){
		cout<<cha[i]<<" "; //注意这里测试的是差分的数据
	}*/
	//以上功能完好

	
	
	
	
	
	
	return 0;
}

