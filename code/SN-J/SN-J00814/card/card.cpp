//SN-J00814
//吴皓轩 
//西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,len;
int a[500011],b[500011],ans[500011];
bool l[500011],s[500011];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)l[j]=false,s[j]=true;
		for(int j=n;j>=i;j--){
			if(l[a[j]]==true)
			{				
			    for(int q=b[a[j]];q<j;q++){
				    s[q]=false;
				}
				b[a[j]]=j;
				l[a[j]]=true;
			}
			else{
				l[a[j]]=true;
				b[a[j]]=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(s[j]==true)ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
