#include<bits/stdc++.h>
#define pic pair<long long,char>
using namespace std;
const int N = 2e5+10;
long long n,num,cnt,ans;
pic a[N];
char ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num>>ch;
		cnt+=num;
		a[i] = {num,ch};
	}
	for(int i=0,j=n-1;i<j;){
		if(a[i].first>a[j].first){
			if(a[i].second != a[j].second)ans+=a[j].first;
			a[i].first-=a[j].first;
			j--;
		}
		if(a[i].first<a[j].first){
			if(a[i].second != a[j].second)ans+=a[i].first;
			a[j].first-=a[i].first;
			i++;
		}
		if(a[i].first==a[j].first){
			if(a[i].second != a[j].second)ans+=a[i].first;
			j--;
			i++;
		}

	}
	cout<<ans<<endl;
}
