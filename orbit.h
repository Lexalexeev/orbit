#include <vector>
#include "vec.cpp"
using namespace std;

const double G = 6.67385 * pow(10.0, -20),
             EarthMass = 5.9742 * pow(10.0, 24),
             EarthRadius = 6378.1,
             ZeroCelsius = 273.15;

//������ �������� � ������������
struct Rotation
{
    double rotationAroundX, rotationAroundY, rotationAroundZ;
};

vec Orient; //������ ���������� � ������������
vec Position; //������ ��������� � ������������

//��������� ���������, ����������, �������� � ������� �������� �������
struct ShipPosition
{
    vec position;
    vec orientation;
    vec speedFirst;
    Rotation moment;
};

//�������, ��������� ������������
struct PartOfFlightPlan
{
    int delayTime; //����� ��������
    double impulseValue; //������� ��������� ������� �������
    Rotation rotateValue; //������ �������� ������ ������ �� ����
};

//��������� �������
struct ShipParams
{
    //����������� ��������� ���� = 3 ��/�^3
    double shipEdgeLength; //�����
    double shipMass; //����� ��� �������
    double fuelMass; //����� �������
    Rotation maxRotation; //������������ ������� ��������
    double maxFuelUsagePerSec; //������������ �������� ������ �������
    double impulsePerFuel; //�������� ������� ���������
    std::vector<PartOfFlightPlan> flightPlan; //������ ������
    double maxOverload; //���������� ����������
    double maxHeating; //������������ ��������
};

struct Quants
{
    int numberOfQuants; //���������� �������� �������
    double quantSizeOfSec; //������ ������� � ��������
};

//������������ �������� ��������� � ��������
struct ReturnValues
{
    //Position position;
    vec position;
    vec speed;
};

std::vector <ReturnValues> computeFlightPlan(ShipPosition initialPosition,
                                             ShipParams shipParams,
                                             Quants quants);