#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;
struct xx{
	long long x;
	char o;
};
xx p[200005];
unsigned long long n,cur,ans,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].x>>p[i].o;
		cur+=p[i].x;
	}
	int ok=cur/2,c=0;
	if(cur%2==1)ok+=1;
	int l=0,r=n-1;
	for(int i=0;i<n-1;i++){
		sum+=p[i].x;
		if(sum+p[i+1].x>ok){
			c=i+1;
			break;
		}
	}sum=0;
	while(1){
		if(l>r)break;
		if(l==r){
			if(sum<0){
				p[l].x-=sum;
				ans+=sum;
				sum=0;
				break;
			}
			if(sum==0)break;
		}
		sum+=p[l].x;
		if(p[r].o!=p[l].o){
			sum-=p[r].x;
			ans+=p[r].x;
		}
		if(sum<=0)l++;
		r--;
	}
	cout<<ans;
	return 0;
}
