#include<bits/stdc++.h> 
using namespace std;
struct n{
	long long num;
	char c;
}a[200007];
unsigned long long sum;
unsigned long long mid=sum/2;
unsigned long long cnt=0;
unsigned long long lstop=0,rstop=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	
	for(int i=1;i<=n;i++){
		sum+=a[i].num;
	}
	//偶 
	mid=sum/2;
//左右剩多少没处理 
	if(sum%2==0){
		lstop=mid;
		rstop=mid+1;
	}else{
		lstop=mid;
		rstop=mid+2;
	}
	int lcnt=1;
	int rcnt=n;
	unsigned long long ans=0;
	unsigned long long lcntjilu=1;
	char l=a[lcnt].c;//当前字母 (左
	char r=a[rcnt].c;
	unsigned sumcn=sum;
	for(int i=0;i<lstop;i++){
		//cout<<i<<" "<<sum+1-i<<endl;
		if(i>lcntjilu){
			lcntjilu+=a[lcnt].num;
			//cout<<lcntjilu<<" "<<i<<" "<<0<<endl;
			lcnt++;
		}
		if(sum-i+1==sumcn-a[rcnt].num){
			sumcn-=a[rcnt].num;

			rcnt--;
			
		}

		//cout<<lcnt<<" "<<rcnt<<endl;
		if(a[lcnt].c!=a[rcnt].c){
			ans++;
			//cout<<"YES"<<endl;
		}
	}
	cout<<ans;
	return 0;
	
}
