#include<bits/stdc++.h>
using namespace std;
int n,m,a[500500],t[300300],f[300300],c[300300],s=1;
//a:牌堆中点数  t：桌面上点数 
// f：点数对应位置  c：点数出现次数 
void ok1(){
	for(int i=1;i<=n;i++){
		s=1;
		memset(t,0,sizeof(t));
		memset(f,0,sizeof(t));
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				for(int k=f[a[j]];k<=s;k++){
					f[t[k]]=0;
				}
				s=f[a[j]]+1;
			}
			t[s]=a[j];
			f[a[j]]=s;
			s++;
		}
		for(int j=1;j<=m;j++){
			if(f[j]) c[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
void ok2(){
	for(int i=1;i<=n;i++){
		f[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
}
void ok3(){
	for(int i=1;i<=n;i++){
		if(a[i]==a[n]) c[a[i]]++;
		else c[1]++,c[2]++;
	}
	cout<<c[1]<<" "<<c[2];
}
void ok4(){
	for(int i=1;i<=n;i++){
		s=1;
		memset(t,0,sizeof(t));
		memset(f,0,sizeof(t));
		for(int j=i;j<=n;j++){
			while(a[j]==a[j+1]){
				j++;if(j>n) break;
			}
			if(f[a[j]]){
				for(int k=f[a[j]];k<=s;k++){
					f[t[k]]=0;
				}
				s=f[a[j]]+1;
			}
			t[s]=a[j];
			f[a[j]]=s;
			s++;
		}
		for(int j=1;j<=m;j++){
			if(f[j]) c[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
int main(){
	freopen("card.out","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int f1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f1=1;
	}
	if(!f1){
		ok2();//7,8,9,20
		exit(0);
	}
	if(m==2){
		ok3();//13,14
		exit(0);
	}
	ok4();//15,16,17,1,2,3,4,5,6
}
