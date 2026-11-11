#include<bits/stdc++.h> 
#define ll long long
using namespace std;

const int N = 2e5+5;

int a[N];
char c[N];
long long len = 0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s;
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len += a[i];
	}
	
	
	
	long long diff = 0;
	// 双指针，指针代表当前扫到的长度
	long long pos = 0;		// 默认从0开始扫
	long long coverL=0,coverR=0;		// 两边的字符串覆盖到的位置
	int cntL=0,cntR=n+1;			// 当前在处理c[cnt]字符串 
	while(pos<len/2&&cntL!=cntR){
		if(pos>=coverL){		// 说明pos已经完成左段的处理 
			cntL++;
			coverL += a[cntL];		// 增加覆盖位置 
		}
		if(pos>=coverR){
			cntR--;
			coverR += a[cntR];
		}
		
		if(cntL==cntR){		// 没有对应的了 
			break;
		}
		if(c[cntL]!=c[cntR]){
			int cur = min(coverL-pos,coverR-pos);		// 把小的处理掉了
			pos += cur;
			diff += cur;
			
		}else{
			long long cur = min(coverL-pos,coverR-pos);
			pos += cur;
		}
	} 
	
	cout<<diff;
	return 0;
}
