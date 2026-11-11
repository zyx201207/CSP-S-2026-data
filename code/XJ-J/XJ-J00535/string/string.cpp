#include <bits/stdc++.h>
using namespace std;
int n;
struct qujian{
	long long num; char c;
}qj[200005];

long long ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;int l = 1,r = n;
	for(int i=1;i<=n;i++){
		cin >> qj[i].num >> qj[i].c;
	}
	long long meet = 0;
	while( l <= r){
		/*
		qj[l].num;
		rsize = qj[r].num;
		qj[l].c;
		qj[r].c;*/
		if(qj[l].num > qj[r].num && qj[l].c != qj[r].c){
			//左区间比 右区间 长 且 字符不相等 
			ans += qj[r].num; //把右区间 全部变成左区间的字符 
			qj[l].num -= qj[r].num; //左区间 剩下的 长度 
			r--;//下一个右区间 
		}
		else if(qj[l].num < qj[r].num && qj[l].c != qj[r].c){
			//右区间比 左区间 长 且 字符不相等
			ans += qj[l].num;//把左区间 全部变成右区间的字符 
			qj[r].num -= qj[l].num;//右区间 剩下的 长度 
			l++;//下一个左区间
		}else if(qj[l].num == qj[r].num && qj[l].c != qj[r].c){//左右区间一样长  且 字符不相等
			ans += qj[l].num;//把左区间 全部变成右区间的字符 
			l++;r--;//左右区间全都不剩了，进入下一个左右区间 
		}else if(qj[l].c == qj[r].c){
			//左右区间字符一样的情况下 
			if(qj[l].num > qj[r].num){
				//若 左区间 大于 右区间
				qj[l].num -= qj[r].num; //左区间 剩下的 长度 
				r--;//下一个右区间 
			}else if(qj[l].num < qj[r].num){
				//若 右区间 大于 左区间
				qj[r].num -= qj[l].num; //左区间 剩下的 长度 
				l--;//下一个左区间 
			}else if(qj[l].num == qj[r].num) {
				l++;
				r--;
			}
		}
		if(l == r) meet = l;
	}
	cout << ans  << endl;
	return 0;
} 
