#include<bits/stdc++.h>
using namespace std;
int a[300005],t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f1=0,f2=0;
	//12112
	//
	int s1=0,s2=0;
	if(m<=2){
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
			
			if(a[j]==1)f1=1;
			if(a[j]==2)f2=1;
			if(a[j]==1&&f1==1){f1=0;s1++;};
			if(a[j]==2&&f2==1){f2=0;s2++;};
		}
	}
	cout<<s1<<" "<<s2;
	}
	else{
		for(int i=1;i<=m;i++)cout<<n<<" ";
	}
return 0;
}
