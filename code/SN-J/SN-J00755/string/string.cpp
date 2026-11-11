//胡嘉骏 SN-J00755 陕西省西安爱知中学
#include<bits/stdc++.h>
using namespace std;
int a[200010];
char s[200010];
char w[20000010];
int main(){
	freopen("string2.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int q=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		for(int j=q;j<=a[i];j++){
			w[j]=s[i];
		}
		q+=a[i];
	}
	int v=0;
	int ans=q;
	for(int i=1;i<=q/2;i++){
		if(w[i]!=w[ans]){
			v++;
		}
		ans--;
	}
	cout<<v<<endl;
	return 0;
}
