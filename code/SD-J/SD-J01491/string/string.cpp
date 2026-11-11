#include<bits/stdc++.h>
using namespace std;
long long n,len,l=1,r,ans;
struct sss{
	long long gs;
	char ch;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].gs>>a[i].ch;
	}
	r=n;
	while(l<r){
		if(a[l].ch==a[r].ch){
			if(a[l].gs>a[r].gs){
				a[l].gs-=a[r].gs;
				r--;
			}
			else if(a[l].gs<a[r].gs){
				a[r].gs-=a[l].gs;
				l++;
			}
			else {
				l++;
				r--;
			}
		}
		else{
			if(a[l].gs>a[r].gs){
				a[l].gs-=a[r].gs;
				ans+=a[r].gs;
				r--;
			}
			else if(a[l].gs<a[r].gs){//刘邦什么时候出新皮肤？ 
				a[r].gs-=a[l].gs;    //不要在出勇者和伴生了！ 
				ans+=a[l].gs;        //刘邦德古拉伯爵2017年5月出的 
				l++;                 //快十周年了！ 
			}                        //比刘邦在位时间都长o(=_=)o 
			else {                   
				ans+=a[r].gs;        //玩刘邦的还是太少了QwQ 
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
