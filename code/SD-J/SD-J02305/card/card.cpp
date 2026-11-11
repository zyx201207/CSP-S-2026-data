#include <bits/stdc++.h>
using namespace std;
int a[500100],s[500100],s1[300100],s2[300100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		int l=1;
		for(int i=k;i<=n;i++){
			if(s1[a[i]]==0){
				s[l++]=a[i];
				s1[a[i]]=l-1;
		//		cout<<l-1<<" "<<s[l-1]<<endl;
			}
			else l=s1[a[i]]+1;
		}
	//	for(int i=1;i<=l;i++) cout<<s[i]<<" ";
		for(int i=1;i<=m;i++) s1[i]=0;
		for(int i=1;i<=l;i++){
			s1[s[i]]++;
		}
		for(int i=1;i<=m;i++){
			if(s1[i]>0) s2[i]++;
		}
		for(int i=1;i<=m;i++) s1[i]=0;
	//	cout<<endl;
	//	break;
	}
	for(int i=1;i<=m;i++) cout<<s2[i]<<" ";
	return 0;
}
