#include <bits/stdc++.h>
using namespace std;
struct Workshop{
	int m_startTime,m_duration,m_endTime;
    int operator<(const Workshop &oprand){
		return m_endTime < oprand.m_endTime;
	}
};
struct Available_Workshops{
	int m_numWorkshops = 0;
	Workshop *m_arrWorkshop = nullptr;
	Available_Workshops(int n): m_numWorkshops(n){
		m_arrWorkshop = new Workshop[m_numWorkshops];
	}~Available_Workshops(){
		delete[] m_arrWorkshop;
	}
};
Available_Workshops* initialize(int *start_time, int *duration, int n){
	Available_Workshops *resPtr = new Available_Workshops(n);
	resPtr->m_numWorkshops= n;
	for (int i=0;i<n;i++){
		resPtr->m_arrWorkshop[i].m_startTime = start_time[i];
		resPtr->m_arrWorkshop[i].m_duration = duration[i];
		resPtr->m_arrWorkshop[i].m_endTime = start_time[i] + duration[i];
	}
	return resPtr;
}
int CalculateMaxWorkshops(Available_Workshops *workshopsPtr){
	if(workshopsPtr->m_arrWorkshop == nullptr) return 0;
	std::sort(workshopsPtr->m_arrWorkshop, workshopsPtr->m_arrWorkshop + workshopsPtr->m_numWorkshops);
	Workshop *lastPtr = &workshopsPtr->m_arrWorkshop[0];
	int res=1;
	for(int i=1;i<workshopsPtr->m_numWorkshops;i++){
		if(lastPtr->m_endTime <= workshopsPtr->m_arrWorkshop[i].m_startTime){
			res++;
			lastPtr = &workshopsPtr->m_arrWorkshop[i];
		}
	}
	return res;
}
int main(int argc,char *argv[]){
	int n;cin >> n;
	int *start_time = new int[n];
	int *duration = new int[n];
	for(int i=0;i<n;i++){
		cin>>start_time[i];
	}
	for(int i=0;i<n;i++){
		cin>>duration[i];
	}
	Available_Workshops * ptr;
	ptr=initialize(start_time,duration,n);
	cout<<CalculateMaxWorkshops(ptr)<<endl;
	return 0;
}
