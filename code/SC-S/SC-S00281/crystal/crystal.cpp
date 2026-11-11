//此程序用作T1-crystel的特殊性质A的测试
//在此性质下，若要使用这种方法的话：
//m不能大于n-1个组???（按草稿纸上的来）
#include  <bits/stdc++.h>
using namespace std;
int movements[500005];
int n,m;
int power[500005];
int process(int a){
    int max=0,add=1;
    for(int i=1;i<a;i++){
        max+=add;
        add++;
    }
    return max;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>power[i];
	}
	sort(power+1,power+n+1);
	int limit=process(n);
	if(m>limit){//get into special process
        //cout<<"process failed"<<endl;
        //return 0;
        int aa=m-limit;
        if(aa%n==0){
            cout<<n<<endl;
            return 0;
        }else{
            cout<<n-1<<endl;
            return 0;
        }
	}
	int now=0,should=2;
	for(int i=1;i<=m;i++){
		if(now==should){
            should++;
            now=0;
        }
        now++;
        movements[i]=should;
    }
    cout<<movements[m]<<endl;
    //test
    //for(int i=1;i<=m;i++){
    //    cout<<movements[i]<<endl;
    //}
    //cout<<"result:"<<movements[m]<<" limit:"<<process(n)<<endl;
    //test finished
    return 0;
}