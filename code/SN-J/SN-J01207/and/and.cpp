#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],temp;
//tools
int fast(int n){
	int ans=2;
	if(n==0) return 1;
	for(int i=0;i<n-1;i++){
		ans*=2;
	}
	return ans;
};
int totwo(int a){
	int ans=0;
 	string s="";
	while(a>0){
		s+=a%2;
		a/=2;
	}
	for(int i=s.size()-1;i>=0;i--){
		ans=ans*10+s[i];
		//cout<<"[ToTwoLog]"<<ans<<"\n";
	}
	return ans;
};
int an(int a,int b){//in进制,out十进制 
a=totwo(a);b=totwo(b);
int ans=0,i=0;
	while(a>0||b>0){
		//cout<<"[log]"<<a%10<<" "<<b%10<<"\n";
		if(a%10==b%10&&a%10==1) ans+=fast(i);
		//cout<<"[fast]"<<fast(i)<<"\n";
		i++;
		a/=10;b/=10;
	}
	return ans;
};

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;

	int j=0;
	for(int i=0;i<n;i++){
		
		cin>>temp;
		if(temp%2!=0) a[j]=temp;
		j++;
	}
	
	sort(a,a+j+1);
	
	int ans=a[0];
	
	for(int i=j;i>j-m;i--){
		ans=(ans,a[i]);
		//cout<<a[i]<<"\n";
	}
	cout<<ans; 
	return 0;
} 
