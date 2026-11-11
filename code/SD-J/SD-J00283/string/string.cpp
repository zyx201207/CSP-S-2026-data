//#include <bits/stdc++.h>
//using namespace std;
//#define ll long long
//const int N=2e5+10;
//int n;
////int a[N];
////char c[N];
////acacacac
//struct duan{
//	int a,c;
//}ac[N];
//stack <duan> st;
//ll cnt,mid,tmp,ans;
//signed main(){
//	//freopen("string.in","r",stdin);
//	//freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	cin >> n;
//	for (int i=0;i<=n;i++){
//		cin >> ac[i].a >> ac[i].c;
//		cout << i << endl;
//		cnt+=ac[i].a;
//	}
//	cout << "aa" << endl;
//	mid=cnt>>1;
//	if (cnt&1){
//		cnt--;
//		for (int i=1;i<=n;i++){//把中间不影响结果的值删掉 
//			tmp+=ac[i].a;
//			if (tmp>mid);
//			ac[i].a--;
//			break;
//		}
//	}
//	bool flag=false;//中间拆分的标志
//	int midrighta,midlefta;
//	char midrightc,midleftc;
//	int k=1;//当前读到哪一个段
//	tmp=0;
////	bool ji=false;
////	if (cnt&1){
////		ji=true;
////	}	
//	while (tmp<=mid){
//		if (tmp+ac[k].a>mid){//需要拆分中间段 
////			k++;
//			flag=true;
//			midrightc=ac[k].c;
//			midrighta=tmp-mid;
//			midleftc=ac[k].c;
//			midlefta=ac[k].a-midrighta;
//			duan tmpduan;
//			tmpduan.a=mid; 
//			st.push(tmpduan);
//			tmp+=ac[k].a;
//			k++;
//		}
//		else{//正常推栈 
//			duan tmpduan;
//			tmpduan.c=ac[k].c;
//			tmpduan.a=ac[k].a;
//			st.push(tmpduan);
//			tmp+=tmpduan.a;
//			k++;
//		}
//	}
//	while (midrighta!=0){
//		if (st.top().a>midrighta){
//			st.top().a-=midrighta;
//			if (st.top().c!=midrightc){
//				ans+=midrightc;
//			}
//			midrighta=0;
//		}
//		else if (st.top().a<midrighta){
//			midrighta-=st.top().a;
//			if (st.top().c!=midrightc){
//				ans+=st.top().a;
//			}
//			st.pop();
//		}else{
//			if (st.top().c==midrightc){ 
//				ans+=st.top().a;
//			}
//			st.pop();
//			midrighta=0;
//		}
//	}
//	while (!st.empty()){
//		if (st.top().a>ac[k].a){
//			st.top().a-=ac[k].a;
//			if (st.top().c!=ac[k].c){
//				ans+=ac[k].a;
//			}
//			k++;
//		}else if (st.top().a<ac[k].a){
//			ac[k].a-=st.top().a;
//			if (st.top().c!=ac[k].c){
//				ans+=st.top().a;
//			}
//			st.pop();
//		}else{
//			if (st.top().c!=ac[k].c){
//				ans+=st.top().a;
//			}
//			st.pop();
//			k++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
string s;
int n,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	ll cnt=0;
	for (int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		cnt+=a[i];
	}
	ll mid=cnt>>1;
	ll aa=0;
	ll res=0;
	for (int i=1;i<=n;i++){
		string tmp;
		for (int j=1;j<=a[i];j++){
			tmp+=c[i];
		}s+=tmp;
	}
	for (int i=1;i<=mid;i++){
		if (s[i]!=s[i+mid])	res++;
	}
	cout << res;
	return 0;
}

