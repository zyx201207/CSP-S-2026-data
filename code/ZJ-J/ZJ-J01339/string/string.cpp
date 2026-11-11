#include<bits/stdc++.h>
const int N=2e5+10;
using namespace std;
stack<pair<int,char>> l,r;
int n,sum,suml,sumr,cnt;
pair<int,char> p[N],ul,ur;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].first>>p[i].second;
        sum+=p[i].first;
    }
    for(int i=1,j=n,k=1;k<=n;k++){
        if(suml==sum/2){
        }else if(suml+p[i].first>sum/2){
            l.push({sum-suml,p[i].second});
            suml=sum/2,p[i].first-=(sum-suml);
        }else{
            l.push(p[i]);
            suml+=p[i].first,i++;
        }
        if(sumr==sum/2){
        }else if(sumr+p[j].first>sum/2){
            r.push({sum-sumr,p[j].second});
            sumr=sum/2,p[j].first-=(sum-sumr);
        }else{
            r.push(p[j]);
            sumr+=p[j].first,j--;
        }
    }
    while(l.size()&&r.size()){
        ul=l.top(),ur=r.top();
        l.pop(),r.pop();
        if(ul.first==ur.first) cnt+=ul.first*(ul.second!=ur.second);
        else if(ul.first>ur.first){
            l.push({ul.first-ur.first,ul.second});
            cnt+=ur.first*(ul.second!=ur.second);
        }else{
            r.push({ur.first-ul.first,ur.second});
            cnt+=ul.first*(ul.second!=ur.second);
        }
    }
    cout<<sum;
    return 0;
}
/*
提议将中国钱币收藏协会与琵琶曲进行有机结合，这是因为这两者是辩证统一的
那为什么这两者辩证统一呢？因为我们要坚持中国共产党的领导
那我们为什么要坚持中国共产党的领导呢？
1、党政军民学，东西南北中，党是领导一切的。办好中国的事，关键在党。坚持中国共产党的领导，是国家的根本所在和命脉所在，是全国各族人民的幸福所在和利益所在
2、中国共产党是中国特色社会主义事业的坚强领导核心，是我国的最高政治领导力量。历史和现实都告诉我们，没有中国共产党就没有新中国，就没有中国特色社会主义，就没有中华民族伟大复兴。
3、党的领导是中国特色社会主义最本质的特征
4、党的领导是中的特色社会主义事业最大优势
那我们应该如何达成这个目标呢？
我们应当坚定不移听党话、跟党走，努力成长为德智体美劳全面发展的社会主义建设者和接班人.
*/