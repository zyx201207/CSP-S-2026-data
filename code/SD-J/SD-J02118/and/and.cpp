#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct myst {
	ll sum;
	bool value[40];
} arr[200010];
ll n,m,ans=-1;
map<ll,bool>p,emptyy;
vector<ll>val[40];
void turnn(ll indexx) {//转二进制并预处理数据
	ll tempp=1,i=0;
	while(tempp<=arr[indexx].sum) {
		if((arr[indexx].sum/tempp)%2==1) {
			val[i].push_back(indexx);
			arr[indexx].value[i]=1;
		}
		tempp*=2;
		i++;
	}
	return;
}
void findd(ll indexx) {//查找答案indexx即当前位数
	if(indexx<0)return;
	map<ll,bool>pp;//满足条件的都暂时放到该处
	ll cntt=1,summ=-10;
	if(val[indexx].size()>=m) {
		//cout<<endl<<indexx<<" 26"<<endl;
		for(int i=0; i<val[indexx].size(); i++) {
			//cout<<i<<" "<<val[indexx][i]<<" "<<p[val[indexx][i]]<<" 28"<<endl;
			if(p[val[indexx][i]]==1) {//满足之前条件
				//cout<<" 30"<<endl;
				pp[val[indexx][i]]=1;//符合条件了准备放到下一次的查找
			}
			if(cntt<=m) {//有可能在这一位后就没有哪一位1的个数大于等于m所以要统计答案
				//因为后面都不符合那么无论哪几个的按位与都一样
				if(cntt==1) {
					summ=arr[val[indexx][i]].sum;//按位与不能从0开始要有初始值
				}
				summ&=arr[val[indexx][i]].sum;
				cntt++;
			}
		}
		ans=max(ans,summ);
		//cout<<"end"<<" "<<ans<<" "<<summ<<endl;
		for(int i=indexx-1; i>=0; i--) {
			p=pp;//由于每一次的p都被更改所以要及时修正
			findd(i);
		}
	}
	return;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>arr[i].sum;
		turnn(i);
	}
	for(int i=35; i>=0; i--) {
		p=emptyy;
		for(int j=1; j<=n; j++) {
			p[arr[j].sum]=1;
		}
		findd(i);
	}
	cout<<ans;
	return 0;
}
/*
读取到数转为二进制存入数组并在val中标记第i位为1的数中有一个的下标为i
因为1000>111所以从最大位开始跑如果当前位为1的数的个数大于等于m那这一位就可以被计入答案
当某一位被选好时有可能出现大于m个数满足条件那么就在这几个数中再找最大答案
*/
