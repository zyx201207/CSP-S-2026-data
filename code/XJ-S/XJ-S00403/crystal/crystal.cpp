#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m,sum=1,ans=1,flag=0,cha;
bool xx(long long a,long long b){
	return a>b;
}
//int plana(){
//	cout<<"aaa"<<endl;
//	
//	sort(a+1,a+n+1,xx);
//	for(int i = 1;i<=n;i++){
//		m-=i;
//		if(m==0)return i+1;
//		else if(m<0)return i;
//	}
//	
//}
int planb(){

	int s=1;
	for(int i = cha;i<=cha*n;i+=cha){
		m-=i;
		if(m==0)return s+1;
		else if(m<0) return s;
		else s++;
	}
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]); 
		if(a[i]==i)flag++;
	}
	sort(a+1,a+n+1,xx);
	cha=a[1]-a[2];
	
	if(a[n]==a[1]-cha*(n-1)){
		
		cout<<planb();
		return 0;
	}

	for(int i = 1;i<=n-1;i++){
		long long t=m;
		sum=1;
		for(int j = i+1;j<=n;j++){
			t-=a[i]-a[j];
			if(t<0)break;
			else sum++;
		}
		if(sum>ans)ans=sum;
	}
	cout<<ans;
	return 0;
} 

/*
5 5
1 2 4 8 9
*/

//这把就靠你了 
