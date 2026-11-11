#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long ans;
int n,a[N];
char ch[N];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d %c",&a[i],&ch[i]);
	for(int i=1,j=n;i<j;)
	{
		if(ch[i]==ch[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}
			else{
				i++; j--;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				ans+=a[j];
				j--;
			}
			else if(a[i]<a[j]){
				a[j]-=a[i];
				ans+=a[i];
				i++;
			}
			else{
				ans+=a[i];
				i++; j--;
			}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
