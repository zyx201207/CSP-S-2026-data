#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int n;
	cin>>n;
	vector<long long> num(n); //个数 
	vector<char> c(n); //对应小写字母
	for (int i=0;i<n;i++){
		cin>>num[i];
		cin>>c[i];
	}
	 
	long long l=num[0],r=num[n-1]; //左右端在当前状态下未遍历的数量 
	int ln=0,rn=n-1; //左右当前所在的 ai处 
	long long count=0; //需要改变的总数  
	long long now; //当前可操作的字母数 
	bool flag=false; //是否相同 
	
	/*cout<<"num: ";
	for (int i=0;i<n;i++) cout<<num[i]<<" ";
	cout<<endl;
	*/
	while(ln<=rn){
		flag=false;
		if (c[ln]!=c[rn]){ //字母不相同（需要修改）
	    	flag=true; //数据不同 
		}
		if (l>r){ //左边更多 
			now=r;
			rn--;
			r=num[rn];
			l-=now; 
		} 
		else if (r>l){ //右边更多 
			now=l;
			ln++; 
			l=num[ln]; //左边跳转到下一位 
			r-=now; //右边减去已处理的数据
		}
		else if (l==r){
			ln++;
			rn--;
			l=num[ln];
			r=num[rn];
			now=l;
		}
		
		//cout<<"l:"<<l<<" r:"<<r<<" ln:"<<ln<<" rn:"<<rn<<" now:"<<now<<" 左侧字母："<<c[ln]<<" 右侧字母："<<c[rn]<<endl;
		
		if (flag) count+=now;
		
	} 
	cout<<count<<endl;
	return 0;
	
}
