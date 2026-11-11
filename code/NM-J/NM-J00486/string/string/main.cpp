#include <bits/stdc++.h>

using namespace std;
int nums=INT_MAX,n;
int main()
{
    freopen("string.in","r",stdin);
        freopen("string.out","w",stdout);

	cin>>n;
	int arr[n+1];
	string s;
	for(int i=1;i<=n;i++){
		cin>>arr[i]>>s[i];
	}
	int num[n];
	for(int i=1;i<=n;i++){
		num[i]=arr[i];
	}
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++){
		int a=arr[i],b=arr[i+1];
		while(a!=b){
			int c=b/a;
			b=a;
			a=c;
		}
		nums=max(a,nums);
	}
	for(int i=1;i<=n;i++){
		arr[i]=arr[i]/nums;
	}
	string ans="";
	for(int i=0;i<s.size();i++){
		for(int i=1;i<=arr[i];i++){
			ans=s[i];
		}
	}
	int z=0;
	for(int i=1;i<=s.size()/2;i++){
		if(ans[i]!=ans[n+1-i]){
			ans[i]=ans[n+1-i];
			z++;
		}
	}
	cout<<z*nums;
    return 0;
}
