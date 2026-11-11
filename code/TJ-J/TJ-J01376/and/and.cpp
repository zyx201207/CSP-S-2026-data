/*
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200200];
long long er[40];
struct node{
	int ch,num;
};
node cha[200200];
bool cmp(int a,int b){
	return a>b;
}
bool cmp2(node a,node b){
	return a.ch<b.ch;
}
bool cmp3(node a,node b){
	return a.num>b.num;
}
 
int main(){
	
	
	
	//保证 2^x-数字 最小,即可保证该数字对应的二进制数的1数量最多 
	er[1]=1;
	for(int i=2;i<=30;i++) er[i]=er[i-1]*2;//前缀积 
	//输入 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=30;j>=1;j--){
			if(er[j]>=a[i]&&er[j-1]<=a[i]){
				cha[i].ch=er[j]-a[i];
				cha[i].num=j-1;
				break;
			}
		}
	}
	sort(cha+1,cha+n+1,cmp2);
	sort(cha+1,cha+m+1,cmp3);
	
	int res=a[cha[1].num];
	for(int i=2;i<=m;i++) res&=a[cha[i].num];
	for(int i=1;i<=m;i++) cout<<cha[i].num<<" "<<cha[i].ch<<endl;
	//cout<<endl<<cha[2].ch;
	cout<<res;
	
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[200200];
struct node{
	int one,num;
};
node nnn[200200];
int getone(int x){
	int res=0;
	while(x){
		res+=(x%2);
		x/=2;
	}
	return res;
}
bool cmp(node a,node b){
	return a.one>b.one;
}
//must delete the //   务必删除freopen的注释！！！
int main(){
	
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	
	//输入 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nnn[i].num=a[i];
		nnn[i].one=getone(a[i]);
	}
	sort(nnn+1,nnn+n+1,cmp);
	int re=a[1];
	for(int i=2;i<=m;i++) re&=a[i];
	cout<<re;
	
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[200200];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	int res=a[1];
	for(int i=2;i<=m;i++) res&=a[i];
	cout<<res;
	
	return 0;
}
