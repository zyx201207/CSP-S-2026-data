# include <bits/stdc++.h>
using namespace std;
long long n,ans,l;
string s;
struct stu{
	char c;
	long long a;
}arr[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].a>>arr[i].c;
		l+=arr[i].a;
	}
	long long tmp1=0,tmp2=0,i=1,j=n;
	while(tmp1<l/2&&tmp2<l/2){
		if(arr[i].c!=arr[j].c) ans+=min(arr[i].a,arr[j].a);
		if(arr[i].a<arr[j].a) {
			tmp1+=arr[i].a;
			tmp2+=arr[i].a;
			arr[j].a-=arr[i].a;
			i++;
		}
		else if(arr[i].a>arr[j].a) {
			tmp1+=arr[j].a;
			tmp2+=arr[j].a;
			arr[i].a-=arr[j].a;
			j--;
		}
		else{
			tmp1+=arr[i].a;
			tmp2+=arr[j].a;
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
} 
