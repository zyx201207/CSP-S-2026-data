#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL> a, d;
vector<char> c;
struct pr{
    LL idx;
    bool li;
};
struct seg{
    pr l, r;
    char c;
};
struct Ev{
    LL idx;
    bool li;
    char c;
    LL len=0;
    Ev(LL _idx, bool _li, char _c):idx(_idx), li(_li), c(_c){}
    bool operator<(const Ev& other)const {return idx<other.idx;}
};
LL lin(LL L, LL x){
//	printf("lin: %d %d\n", L, x);
    if(x==L/2 && L%2==1)return 2;
    if(x>=L/2)return 1; 
    return 0;
}
vector<Ev> ev;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	LL L=0, n;
    cin>>n;
    a.resize(n);
    d.resize(n);
    c.resize(n);
    cin>>a[0]>>c[0];
//    cout<<a[0]<<'\n';
    L+=a[0];
    d[0]=a[0];
    for(LL i=1; i<n; i++){
        cin>>a[i]>>c[i];
        L+=a[i];
//        cout<<L<<'\n';
        d[i]=d[i-1]+a[i];
    }
    LL mid=L/2;
    bool issig=L%2;
    LL maxsize=0;
    for(LL i=0; i<n; i++){
        LL nowl=d[i]-a[i], nowr=d[i]-1; // [nowl, nowr]
//        printf("nowl:%d nowr:%d\n", nowl, nowr);
        bool linel=0, liner=0;
        if(lin(L, nowl)==2){
//        	cout<<"detected "<<nowl<<endl;
            nowl++;
        }
        if(lin(L, nowr)==2){
            nowr--;
        }
        if((lin(L, nowl)==2 && lin(L, nowr)==2) || nowl>nowr){
            continue;
        }
        if(lin(L, nowl)==1){
            nowl=L-nowl-1;
            linel=1;
        }
        if(lin(L, nowr)==1){
            nowr=L-nowr-1;
            liner=1;
        }
//        printf("nowl:%d nowr:%d\n", nowl, nowr);
        if(nowl>nowr){
            swap(nowl, nowr);
            swap(linel, liner);
        }
        liner=linel;
        ev.push_back(Ev(nowl, linel, c[i]));
        maxsize=max(maxsize, nowr);
    }
    sort(ev.begin(), ev.end());
    char line[2]={0};
	ev.push_back(Ev(maxsize, 0, 255));  
    LL ans=0;
    for(LL i=0; i<ev.size()-1; i++){
		ev[i].len=ev[i+1].idx-ev[i].idx; 
	} 
//    for(LL i=0; i<ev.size(); i++)printf("ev[%d]={idx=%d, li=%d, c=%d, len=%d}\n", i, ev[i].idx, ev[i].li, ev[i].c, ev[i].len); 
    for(LL i=0; i<ev.size(); i++){
    	Ev &now=ev[i];
        line[now.li]=now.c;
        if(line[0]!=line[1]){
        	ans+=now.len;
		}
    }
    cout<<ans;
	return 0; 
}
