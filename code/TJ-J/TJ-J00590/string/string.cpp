#include<iostream>
using namespace std;
struct duan{
	long long num;
	char cha;
}arr[200005];
char c;
long long n,tmp,l=1,r=1,cnt1=0,cnt2=0,ans=0;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tmp>>c;
		if(c==arr[r-1].cha) arr[r-1].num+=tmp;
		else{
			arr[r].num=tmp;
			arr[r++].cha=c;
		}
	}
//	for(int i=1;i<l;i++){
//		for(int j=1;j<=arr[i].num;j++) cout<<arr[i].cha;
//	}
	while(l<r){
		if(arr[l].cha==arr[r-1].cha){
			if(arr[l].num>arr[r-1].num){
				arr[l].num-=arr[r-1].num;
				r--;
			}
			else if(arr[l].num==arr[r-1].num){
				l++,r--;
			}
			else{
				arr[r-1].num-=arr[l].num;
				l++;
			}
		}else{
			if(arr[l].num>arr[r-1].num){
				arr[l].num-=arr[r-1].num;
				ans+=arr[r-1].num;
				r--;
			}
			else if(arr[l].num==arr[r-1].num){
				ans+=arr[r-1].num;
				l++,r--;
			}
			else{
				arr[r-1].num-=arr[l].num;
				ans+=arr[l].num;
				l++;
			}
		}
	}
	
	cout<<ans;
	return 0;
}
