#include <vector>

//������ ��������� � ������������
struct vec
{
    double x, y, z;
};

//������ �������� � ������������
struct Rotation
{
    double rotationAroundX, rotationAroundY, rotationAroundZ;
};

typedef vec Orient; //������ ���������� � ������������
typedef vec Position; //������ ��������� � ������������
typedef Rotation RotationSpeed; //������ �������� �������� ������ ���� ����

//��������� ���������, ���������� � �������� �������
struct ShipPosition
{
    Position position;
    Orient orientation;
    vec speedFirst;
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
    Position position;
    vec speed;
};

std::vector <ReturnValues> computeFlightPlan(ShipPosition initialPosition,
                                             ShipParams shipParams,
                                             Quants quants);